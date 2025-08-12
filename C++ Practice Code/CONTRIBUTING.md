# 贡献指南 (Contributing Guidelines)

感谢您对DUKE ECE-551 C++练习代码项目的关注！我们欢迎各种形式的贡献。

## 🤝 如何贡献

### 报告问题 (Reporting Issues)

如果您发现了bug或有改进建议，请：

1. 检查是否已有相关的Issue
2. 创建新的Issue，包含以下信息：
   - 问题的详细描述
   - 重现步骤
   - 期望的行为
   - 实际的行为
   - 系统环境信息

### 提交代码 (Submitting Code)

1. **Fork项目**
   ```bash
   git clone https://github.com/your-username/DUKE-ECE-551.git
   cd "C++ Practice Code"
   ```

2. **创建分支**
   ```bash
   git checkout -b feature/your-feature-name
   # 或者
   git checkout -b fix/your-bug-fix
   ```

3. **编写代码**
   - 遵循项目的代码规范
   - 添加适当的中文注释
   - 确保代码能够正常编译和运行

4. **测试代码**
   ```bash
   # 编译测试
   g++ -std=c++11 your_file.cpp -o test
   ./test
   ```

5. **提交更改**
   ```bash
   git add .
   git commit -m "feat: 添加新的模板特化示例"
   # 或者
   git commit -m "fix: 修复内存泄漏问题"
   ```

6. **推送分支**
   ```bash
   git push origin feature/your-feature-name
   ```

7. **创建Pull Request**
   - 提供清晰的PR标题和描述
   - 说明更改的内容和原因
   - 如果解决了Issue，请在描述中引用

## 📝 代码规范

### C++代码规范

1. **命名规范**
   ```cpp
   // 变量和函数：小写字母+下划线
   int student_count = 0;
   void calculate_average();
   
   // 类名：大写字母开头的驼峰命名
   class StudentManager;
   
   // 常量：全大写+下划线
   const int MAX_STUDENTS = 100;
   ```

2. **注释规范**
   ```cpp
   // 使用中文注释说明关键逻辑
   template <typename T>
   T add(T t1, T t2) {
       return t1 + t2; // 返回两个参数的和
   }
   
   // 针对const char*类型的特化实现
   template <>
   const char* add<const char*>(const char* p1, const char* p2) {
       // 分配足够的内存空间
       char* ptemp = new char[strlen(p1) + strlen(p2) + 1]();
       strcpy(ptemp, p1);  // 复制第一个字符串
       strcat(ptemp, p2);  // 连接第二个字符串
       return ptemp;
   }
   ```

3. **代码格式**
   - 使用4个空格缩进
   - 大括号另起一行
   - 适当的空行分隔逻辑块

### 文件组织

```
新增练习/
├── README.md          # 练习说明
├── example.cpp        # 主要代码文件
├── example.hpp        # 头文件（如需要）
├── Makefile          # 编译脚本（如需要）
└── test_data/        # 测试数据（如需要）
```

## 🎯 贡献类型

### 欢迎的贡献

1. **代码改进**
   - 修复bug
   - 性能优化
   - 代码重构
   - 添加错误处理

2. **新增内容**
   - 新的练习示例
   - 算法实现
   - 设计模式示例
   - 最佳实践演示

3. **文档完善**
   - 改进README
   - 添加代码注释
   - 编写教程
   - 翻译文档

4. **测试用例**
   - 单元测试
   - 集成测试
   - 性能测试
   - 边界条件测试

### 不建议的贡献

- 与课程内容无关的代码
- 违反学术诚信的解决方案
- 未经测试的代码
- 缺乏注释的复杂代码

## 🔍 代码审查

所有的Pull Request都会经过代码审查：

1. **自动检查**
   - 代码编译测试
   - 格式检查
   - 基本的静态分析

2. **人工审查**
   - 代码质量
   - 逻辑正确性
   - 注释完整性
   - 与项目目标的一致性

## 📚 学习资源

- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [Modern C++ Features](https://github.com/AnthonyCalandra/modern-cpp-features)

## 🙋‍♂️ 获取帮助

如果您在贡献过程中遇到问题：

1. 查看现有的Issues和Discussions
2. 创建新的Issue描述您的问题
3. 在Pull Request中@相关的维护者

## 📄 许可证

通过贡献代码，您同意您的贡献将在MIT许可证下发布。

---

再次感谢您的贡献！每一个贡献都让这个学习资源变得更好。