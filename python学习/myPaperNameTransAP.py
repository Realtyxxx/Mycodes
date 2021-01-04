string ="Energy-Aware Device Drivers for Embedded Operating Systems"
res = ""
for i in string:
	if i == ' ':
		i = '_'
	res+=i
print(res)