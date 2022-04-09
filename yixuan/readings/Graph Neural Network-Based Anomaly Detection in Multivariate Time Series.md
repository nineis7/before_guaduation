**核心思路**：图神经网络学习不同时间序列之间的关系

将GNNs应用于时间序列异常检测需要克服两个主要挑战。<br />Firstly, different sensors have very different behaviors: e.g. one may measure water pressure, while another measures flflow rate. However, typical GNNs use the same model parameters to model the behavior of <br />each node. <br /> Secondly, in our setting, the graph edges (i.e. relationships between sensors) are initially unknown, and have to be learned along with our model, while GNNs typically treat the graph as an input.

包括四个主要部分:

1. Sensor Embedding:利用嵌入向量灵活地捕捉每个传感器的独特特征
1. Graph Structure Learning:学习传感器之间的关系，并把它们视作图边
1. Graph Attention-Based Forecasting:根据图中邻近传感器的注意力函数，预测传感器未来的行为
1. Graph Deviation Scoring:图偏差评分识别并解释图中所学习的传感器关系的偏差。

[<br />](https://blog.csdn.net/weixin_42358688/article/details/120280942)贡献：

1. 提出GDN,一种基于注意力的图神经网络，以此去学习传感器之间的关系依赖图，并识别和解释这些关系的偏差
1. 我们在两个水处理厂的真实异常数据集上进行了实验。我们的结果表明，GDN检测异常比基线方法更准确。
1. 我们通过案例研究表明，GDN通过其嵌入和学习图提供了一个可解释的模型。我们表明，基于检测到偏差的子图、注意力权重，并通过比较这些传感器上的预测和实际行为，它有助于解释异常。

[<br />](https://blog.csdn.net/weixin_42358688/article/details/120280942)![EX@~}TZ3HG3F[UA(H_ZR5(G.png](https://cdn.nlark.com/yuque/0/2022/png/25902650/1649499071551-41c5e88b-960e-4580-bf37-0239d7118971.png#clientId=u5ce7f75d-ba4e-4&crop=0&crop=0&crop=1&crop=1&from=drop&id=ucdf97fd3&margin=%5Bobject%20Object%5D&name=EX%40~%7DTZ3HG3F%5BUA%28H_ZR5%28G.png&originHeight=932&originWidth=1095&originalType=binary&ratio=1&rotation=0&showTitle=false&size=159688&status=done&style=none&taskId=u11f932ce-b0e9-42b6-b60a-ee122da6f27&title=)
