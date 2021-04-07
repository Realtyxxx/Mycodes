#!/usr/bin/env python3 
# -*- coding: utf-8 -*-
#! author = bsb888
#! date: 2019年9月9日
 
import  hashlib
 
 
def has_valid_license():
    l = []
    email = "tyx627@icloud.com"
    # 这个email 可以自己进行自定义
    hash_object = hashlib.md5(email.encode('utf-8'))
    hex_digest = hash_object.hexdigest()
    for i in range(0, len(hex_digest), 5):
        if i <21:
            a = hex_digest[i:i + 5]
            l.append(a)
        else:
            pass
        license_key = '-'.join(l)
    print("激活码license_key为：{0}".format(license_key))
# "email": "id@chinapyg.com"
    license = """
{
 "email": "841344563@qq.com",
 "license_key": "10988-becc3-31e35-87fda-a0059"
}
只需要修改相应的key和email就好，默认为上面的激活码~
    """
    # print(license)
 
has_valid_license()