### WordFrequency
#### **词频统计**
2018/6/15
- Records.txt文件用于文段内全部单词的输出。
- 支持对文本中单词与符号连在一起时，单独统计单词。忽略如Auto-Machine一类的中间符号，仅去除词前与词尾。
	- 如句尾英文模式下的‘.’与单词连在一起。e.g.: This is the ending.会提取ending，忽略.句号之后的空格也会被忽略。
	- 如一些被修订过的文本中的（was）或者 [colour] 等。仅提取单词，忽略符号。
	- 单词首字母大小写忽略，全大写单词转换为小写，当做相同单词统计。

---------
- GUI待制作。
- 利用函数指针精简代码。
- 使用哈希，加快处理速度。
