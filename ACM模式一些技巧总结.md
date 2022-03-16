## ACM模式一些技巧总结

1. 万能头文件

   `include<bits/stdc++.h>`

2. 可以用如下方式读取数据，直到文件尾部：

   ```
   while(cin >> n){
   	
   }
   ```

3. 用如下方法检测换行，效果等同于C语言的getchar:

   ```
   if(cin.get() == '\n')
   ```

4. 行数不确定，每行输入个数不确定，还可以用如下方法：

   ```c++
   string line;
   while(get(cin,line)){
   	stringstream ss;
   	ss << line;
   	int a;
   	while(ss >> a){
   		
   	}
   }
   ```

5. 如果上述第四点每行间隔不再是空格而是逗号怎么办？

   ```c++
   #include<bits/stdc++.h>
   using namespace std;
   int main(){
       string s;
       while(getline(cin,s)){
           vector<string> ret;
           stringstream ss(s);
           while(getline(ss,s,',')){
               ret.push_back(s);
           }
           sort(ret.begin(),ret.end());
           for(int i = 0;i < ret.size() - 1;i++){
               cout << ret[i] << ',';
           }
           cout << ret[ret.size() - 1] << endl;
       }
   }
   ```

6. 当你笔试的时候怀疑系统或者题目数据有问题的时候请务必先怀疑自己的代码!

   + 你对题目理解错了，你的代码只过了样例或你自己的数据
   + 你的代码逻辑有问题，你的代码只过了样例或你自己的数据

   **比如数据大小可能太大，建议用long**