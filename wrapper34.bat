@echo off
:: add necessary paths to PYTHONPATH
SET PYTHONPATH=output/python3.4:output/python3.4/lib-dynload
:: run embedpy app
output\embedpy34.exe %*