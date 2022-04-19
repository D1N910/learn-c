# 二叉树 先/中/后序遍历

- 遍历：按照某种次序把所有结点都访问一遍

线性结构，从左到右遍历

层析遍历：一层一层

根的递归特性：
- 要么就是个空二叉树
- 要么就是由“根节点+左子树+右子树”组成的二叉树

先序遍历：根左右（NLR）—— 先根遍历

中序遍历：左根右（LNR）—— 中根遍历

后序遍历：左右根（LRN）—— 后根遍历

对于只有一个的，e.g. D 先中后都是 D

先序遍历 —— 前缀表达式
中序遍历 —— 中缀表达式（序号加界限符）
后序遍历 —— 后缀表达式