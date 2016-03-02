@echo off
:: add necessary paths to PYTHONPATH
SET PYTHONPATH=output/python2.7:output/python2.7/lib-dynload
:: run embedpy app
output\embedpy.exe %*