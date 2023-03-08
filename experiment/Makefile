##############################################################
#### simple
# directory
d?=01-LED-blink#
#### detail
proj=./$(d)#
proj_bin=$(proj)/bin#
bin=./bin#

default: run

run:
	@make -C $(proj)
#	echo "$(bin)"
#	echo "$(proj_bin)"
# 删除当下 bin 目录
	-@rm -r $(bin)
# 移动到当下 bin 目录
	@mv $(proj_bin) $(bin)
	@echo "Done!"

.PHONY: run
