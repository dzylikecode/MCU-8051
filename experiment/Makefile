##############################################################
#### simple
# directory
d?=01-LED-blink/ 
n?=template
#### detail
proj=$(d)
proj_bin=$(proj)/bin
bin=./bin
utils=../utils
name=$(n)

default: run

# 创建软链接
$(bin):
	@ln -s $(proj_bin) $(bin)

run: $(bin)
	@make -C $(proj)
# 修改软链接
	@ln -snf $(proj_bin) $(bin)
	@echo "Done!"

ini:
	@make -C $(utils) ini n=$(n)
	

.PHONY: run ini
