# lib

`vs8051.h`, `vs8052.h`是为了 cheat VSCode 存在的, 构建步骤如下:

- 使用正则替换

  `__s.*? __at \(.*?\)` -> `#define`

  `;` -> ` `

- 替换宏

  `REG` -> `VS`
