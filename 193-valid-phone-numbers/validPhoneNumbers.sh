# Why doesn't `\d` work in regular expressions in sed?
# https://stackoverflow.com/questions/14671293/why-doesnt-d-work-in-regular-expressions-in-sed
# [0-9]可以，\d不可以
# 括号里面再加括号需要转义？
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt

# 命令那么多。。又不熟。。。
# sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt
