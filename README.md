# -三维CAD建模大程作业-
## 作业要求
1）定义半边数据结构；2）基于半边数据结构，实现五个基本欧拉操作；3）基于欧拉操作，实现扫掠操作（必须允许二维区域带多个内环），并将基于扫掠操作构建的实体模型进行真实感图形显示。<br>
## 项目环境
项目使用*visual studio 2022*进行开发
使用OpenGL进行图形显示，加载了*GLUT,GLFW3,GLM*库 <br>
## 使用说明
加载了相关库后，导入hpp和cpp文件就可以直接调试并运行了，会根据main函数中的cube函数搭建的模型进行绘制。<br>
## 项目成果
基于半边数据结构，实现了mvfs,mev,mef,kemr,kfmrh五个基本的欧拉操作，以及sweep扫掠操作。并用欧拉操作构建了一个五边形，再用扫掠操作构建出实体模型，且绘制了真实图形。 <br>
### 欧拉操作部分
```
Vertex *v[9];
solid = EulerOp::mvfs(v[0], glm::vec3(0.7, 1.1, 0.0));
Face *topFace = solid->Sfaces;
Loop *top = topFace->Floops;
EulerOp::mev(v[0], v[1], glm::vec3(-0.4, 1.6, 0.0), top);
EulerOp::mev(v[1], v[2], glm::vec3(-1.2, -0.5, 0.0), top);
EulerOp::mev(v[2], v[3], glm::vec3(0, -1.5, 0.0), top);
EulerOp::mev(v[3], v[4], glm::vec3(1.0, 0.8, 0.0), top);
EulerOp::mef(v[4], v[0], top);
```
构建了一个五边形
```
solid = Sweep::sweep(topFace, glm::vec3(0.0, 0.0, 1.0), 1.5);
```
再经过扫掠构建出五棱柱，如下图所示，每个面用不同的颜色区分
![2c14e2603e88b225bfbaadcbaf04c51](https://github.com/EJIA66/-CAD-/assets/149877573/8ec235ae-f547-4771-abde-5c6b420a722e)
