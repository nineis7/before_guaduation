无监督图像异常检测
**核心思路**：用不同位置、大小、方向的条状物抠掉原图，用gan重构原图
贡献：新网络、多scale、新数据集LaceAD
![image.png](https://cdn.nlark.com/yuque/0/2022/png/25902650/1649119000884-1495a354-ed50-4b9a-b245-62f743c40082.png#clientId=ub7140f92-83c1-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=485&id=u0020f042&margin=%5Bobject%20Object%5D&name=image.png&originHeight=970&originWidth=2137&originalType=binary&ratio=1&rotation=0&showTitle=false&size=568142&status=done&style=none&taskId=uae51f457-3e37-4426-98cc-431931d826f&title=&width=1068.5)
remove的原则：
(i) the image regions should have the _equal probability _to be removed, since the anomalies may appear in any position of the image; 
(ii) the removed regions should have _multiple scales_, since the anomalies in the real world may have different sizes; 
(iii) the shape of the removed regions should have _multiple directions_, and we can obtain the semantic context from surrounding in different directions.![image.png](https://cdn.nlark.com/yuque/0/2022/png/25902650/1649119020313-116db59f-c714-4250-bd8e-95e10f23f5aa.png#clientId=ub7140f92-83c1-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=312&id=u7dacafde&margin=%5Bobject%20Object%5D&name=image.png&originHeight=623&originWidth=986&originalType=binary&ratio=1&rotation=0&showTitle=false&size=90289&status=done&style=none&taskId=u19ae51e7-30d4-4dc1-9fe0-757b2bfc25f&title=&width=493)
element-wise multiplication=element-wise product=Hadamard product=矩阵对应元素相乘
Loss function
![image.png](https://cdn.nlark.com/yuque/0/2022/png/25902650/1649120635293-fec60293-c087-4437-b4cb-497927cbe1eb.png#clientId=ub7140f92-83c1-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=60&id=u1c241f84&margin=%5Bobject%20Object%5D&name=image.png&originHeight=119&originWidth=750&originalType=binary&ratio=1&rotation=0&showTitle=false&size=13019&status=done&style=none&taskId=u09dd16e5-563e-475c-961b-21dc91b2a8a&title=&width=375)没搞懂，loss是矩阵？

![image.png](https://cdn.nlark.com/yuque/0/2022/png/25902650/1649122331034-a75be422-38aa-484c-af31-0f36471d622a.png#clientId=ub7140f92-83c1-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=346&id=u7e421efa&margin=%5Bobject%20Object%5D&name=image.png&originHeight=691&originWidth=1007&originalType=binary&ratio=1&rotation=0&showTitle=false&size=264075&status=done&style=none&taskId=u08b920fa-88e7-4ea4-b9d9-d49bc662246&title=&width=503.5)
三种大小scale，四种方向
同scale选四种方向差别最大的作为每个scale的error
最后一步合成没看懂
![image.png](https://cdn.nlark.com/yuque/0/2022/png/25902650/1649123151520-1b44fbc5-b1a3-4bff-9a82-e98130f90215.png#clientId=ub7140f92-83c1-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=272&id=u07987f25&margin=%5Bobject%20Object%5D&name=image.png&originHeight=543&originWidth=1036&originalType=binary&ratio=1&rotation=0&showTitle=false&size=113762&status=done&style=none&taskId=u8c9781d2-ba61-4c8b-ad57-214c345be67&title=&width=518)



