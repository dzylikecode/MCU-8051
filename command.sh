function repos-install(){
    sudo apt-get install sdcc # sdcc 编译器
}

function repos-uninstall(){
    sudo apt-get remove sdcc # sdcc 编译器
    sudo apt-get autoremove # remove unused packages
}
