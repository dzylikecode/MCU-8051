# template
cc = sdcc
bin = ./bin
target_name = main
target_hex = $(bin)/$(target_name).hex
target_ihx = $(bin)/$(target_name).ihx
source = main.c
inc = -I..
default: $(target_hex)


################################################################
# compile

$(target_ihx): $(source)
# create bin directory if not exist
	@test -d $(bin) || mkdir $(bin) 
	sdcc -mmcs51 $(inc) $(source) -o $(target_ihx)

################################################################
# target hex

$(target_hex): $(target_ihx)
	packihx $(target_ihx) > $(target_hex)