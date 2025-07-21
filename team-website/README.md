# 智创先锋队 - 团队介绍网站

🚀 一个现代化的AI智能体开发团队介绍网站

## 🌟 特性

- ✨ 现代化响应式设计
- 🎨 科技感十足的视觉效果
- 📱 完美支持移动端
- 🔄 平滑滚动动画
- 🎯 粒子背景效果
- 💫 交互式元素动画

## 📁 文件结构

```
team-website/
├── index.html          # 主页面
├── style.css           # 样式文件
├── script.js           # JavaScript功能
└── README.md           # 说明文档
```

## 🚀 快速开始

### 1. 直接使用
- 双击 `index.html` 文件即可在浏览器中打开
- 或者将文件夹部署到任何Web服务器

### 2. 本地开发服务器
如果你想要更好的开发体验，可以使用以下方式：

```bash
# 使用Python启动本地服务器
python -m http.server 8080

# 或使用Node.js
npx http-server

# 或使用Live Server扩展（VS Code）
```

## 🎨 自定义配置

### 修改团队信息

在 `index.html` 中找到以下部分并修改：

```html
<!-- 团队名称 -->
<h1>智创先锋队</h1>

<!-- 团队口号 -->
<p class="hero-slogan">"智能驱动未来，协作实现卓越"</p>

<!-- 团队成员信息 -->
<div class="team-card">
    <h3>你的姓名</h3>
    <p class="role">你的职位</p>
    <!-- 更多信息... -->
</div>
```

### 修改联系方式

```html
<!-- 联系信息 -->
<div class="contact-item">
    <i class="fas fa-envelope"></i>
    <span>your-email@example.com</span>
</div>
```

### 修改颜色主题

在 `style.css` 中修改CSS变量：

```css
:root {
    --primary-color: #60a5fa;    /* 主要颜色 */
    --secondary-color: #a855f7;  /* 次要颜色 */
    --dark-bg: #0f172a;          /* 深色背景 */
}
```

## 📸 功能说明

### 1. 导航功能
- 固定顶部导航栏
- 平滑滚动到对应部分
- 移动端汉堡菜单

### 2. 响应式设计
- 适配所有设备尺寸
- 移动端优化布局
- 触摸友好的交互

### 3. 动画效果
- 滚动触发的元素动画
- 粒子背景效果
- 悬停交互动画

### 4. 实用功能
- 联系信息一键复制
- 社交媒体链接
- 性能优化

## 🛠️ 技术栈

- **HTML5**: 语义化标记
- **CSS3**: 现代样式和动画
- **JavaScript ES6+**: 交互功能
- **Font Awesome**: 图标库
- **Intersection Observer API**: 滚动动画

## 📱 浏览器支持

- Chrome (推荐)
- Firefox
- Safari
- Edge
- 移动端浏览器

## 🎯 部署选项

### 1. GitHub Pages
```bash
# 1. 创建GitHub仓库
# 2. 上传文件到仓库
# 3. 在Settings中启用Pages
# 4. 选择main分支作为源
```

### 2. Netlify
- 直接拖拽文件夹到 netlify.com
- 或连接GitHub仓库自动部署

### 3. Vercel
```bash
# 安装Vercel CLI
npm i -g vercel

# 在项目目录运行
vercel
```

### 4. 腾讯云静态网站托管
- 上传文件到对象存储
- 配置静态网站托管
- 绑定自定义域名

## 📝 自定义指南

### 添加新的团队成员

1. 复制现有的团队卡片HTML结构
2. 修改成员信息
3. 根据需要调整CSS样式

### 添加新的部分

1. 在HTML中添加新的section
2. 在CSS中添加对应样式
3. 在JavaScript中添加导航链接

### 修改动画效果

在 `script.js` 中找到对应的动画函数并修改参数：

```javascript
// 修改动画延迟
element.style.transition = `all 0.6s ease ${index * 0.2}s`;

// 修改粒子数量
const particleCount = 100;
```

## 🔧 常见问题

### Q: 如何修改LOGO？
A: 可以替换Font Awesome图标或添加图片LOGO

### Q: 如何添加更多页面？
A: 创建新的HTML文件并在导航中添加链接

### Q: 如何优化加载速度？
A: 压缩图片，使用CDN，启用浏览器缓存

### Q: 移动端菜单不工作？
A: 确保JavaScript正常加载，检查控制台错误

## 📄 许可证

MIT License - 你可以自由使用、修改和分发此代码

## 🤝 贡献

欢迎提交Issue和Pull Request来改进这个项目！

## 📞 支持

如果你需要帮助或有任何问题，可以：

1. 查看文档
2. 提交GitHub Issue
3. 联系团队成员

---

**祝你的团队网站搭建成功！🎉** 