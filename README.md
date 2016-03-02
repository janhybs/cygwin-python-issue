# cygwin-python-issue
Demonstration of cygwin's Embedded Python error

## HOWTO

### Under cygwin
1. run ` make all`
2. copy out all dependencies (DLLs) to `output` folder, you can use `make ldd` to find out what to copy
3. copy whole python2.7 folder from `/usr/lib/python2.7/` to `output` folder

### Under Windows
 1. run wrapper.bat

### Conclusion
Result should differ:
Cygwin `./output/embedpy`:
```bash
Python path: /usr/lib/python27.zip:/usr/lib/python2.7/:/usr/lib/python2.7/plat-cygwin:/usr/lib/python2.7/lib-tk:/usr/lib/python2.7/lib-old:/usr/lib/python2.7/lib-dynload
Python prefix: /usr
Python exec prefix: /usr
Time test
Today is Wed Mar  2 11:41:04 2016
binascii test 1
▒▒
binascii test 2
```

Windows `wrapper.bat`:
```
Python path: output/python2.7:output/python2.7/lib-dynload:/usr/lib/python27.zip:/usr/lib/python2.7/:/usr/lib/python2.7/plat-cygwin:/usr/lib/python2.7/lib-tk:/usr/lib/python2.7/lib-old:/usr/lib/lib-dynload
Python prefix: /usr
Python exec prefix: /usr
Time test
Today is Wed Mar  2 11:51:41 2016
binascii test 1
Traceback (most recent call last):
  File "<string>", line 1, in <module>
LookupError: unknown encoding: hex
binascii test 2
Traceback (most recent call last):
  File "<string>", line 1, in <module>
```
