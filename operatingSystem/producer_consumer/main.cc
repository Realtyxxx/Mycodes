#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

static const int repository_size = 10;  //循环队列的大小
static const int item_total      = 20;  //要生产的产品数目

std::mutex mtx;  //互斥量，保护产品缓冲区

std::condition_variable repo_not_full;  //条件变量指示产品缓冲区不满
std::condition_variable repo_not_empty;  //条件变量指示产品缓冲区不为空，就是缓冲区有产品

int item_buffer[repository_size];

static std::size_t read_position  = 0;  //消费者读取产品的位置
static std::size_t write_position = 0;  //生产者写入产品的位置

std::chrono::seconds t(1);  // a new feature of c++ 11 standard

void produce_item(int i) {
  std::unique_lock<std::mutex> lck(mtx);
  while (((write_position + 1) % repository_size) == read_position) {
    std::cout << "Producer is waiting for an empty slot..." << std::endl;
    repo_not_full.wait(lck);  // 生产者等待"产品库缓冲区不为满"这一条件发生.
  }                           //当缓冲区满了之后我们就不能添加产品了

  item_buffer[write_position] = i;  //写入产品
  write_position++;

  if (write_position == repository_size)  //写入的位置如果在队列最后则重新设置
  {
    write_position = 0;
  }

  repo_not_empty.notify_all();  //通知消费者产品库不为空

  // lck.unlock();//解锁
}

int consume_item() {
  int                          data;
  std::unique_lock<std::mutex> lck(mtx);
  while (write_position == read_position) {
    std::cout << "Consumer is waiting for items..." << std::endl;
    repo_not_empty.wait(lck);  // 消费者等待"产品库缓冲区不为空"这一条件发生.
  }

  data = item_buffer[read_position];  //读取产品
  read_position++;

  if (read_position >= repository_size) {
    read_position = 0;
  }

  repo_not_full.notify_all();  //通知产品库不满
  // lck.unlock();

  return data;
}

void Producer_thread() {
  for (int i = 1; i <= item_total; ++i) {
    // std::this_thread::sleep_for(t);
    std::cout << "生产者生产第" << i << "个产品" << std::endl;
    produce_item(i);
  }
}

void Consumer_thread() {
  static int cnt = 0;
  while (1) {
    // std::this_thread::sleep_for(t);
    int item = consume_item();
    std::cout << "消费者消费第" << item << "个产品" << std::endl;

    if (++cnt == item_total) break;
  }
}

int main() {
  std::thread producer(Producer_thread);  // 创建生产者线程.
  std::thread consumer(Consumer_thread);  // 创建消费之线程.
  producer.join();
  consumer.join();
}