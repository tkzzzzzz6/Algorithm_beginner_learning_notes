// DOM 加载完成后执行
document.addEventListener('DOMContentLoaded', function() {
    
    // 平滑滚动功能
    function initSmoothScroll() {
        const navLinks = document.querySelectorAll('.nav-menu a[href^="#"]');
        const heroButtons = document.querySelectorAll('.hero-buttons a[href^="#"]');
        
        [...navLinks, ...heroButtons].forEach(link => {
            link.addEventListener('click', function(e) {
                e.preventDefault();
                
                const targetId = this.getAttribute('href');
                const targetSection = document.querySelector(targetId);
                
                if (targetSection) {
                    const offsetTop = targetSection.offsetTop - 80; // 考虑导航栏高度
                    
                    window.scrollTo({
                        top: offsetTop,
                        behavior: 'smooth'
                    });
                }
            });
        });
    }
    
    // 移动端导航菜单
    function initMobileNav() {
        const hamburger = document.querySelector('.hamburger');
        const navMenu = document.querySelector('.nav-menu');
        
        if (hamburger && navMenu) {
            hamburger.addEventListener('click', function() {
                hamburger.classList.toggle('active');
                navMenu.classList.toggle('active');
            });
            
            // 点击菜单项后关闭移动菜单
            document.querySelectorAll('.nav-menu a').forEach(link => {
                link.addEventListener('click', function() {
                    hamburger.classList.remove('active');
                    navMenu.classList.remove('active');
                });
            });
        }
    }
    
    // 滚动时的导航栏效果
    function initNavbarScroll() {
        const navbar = document.querySelector('.navbar');
        
        window.addEventListener('scroll', function() {
            if (window.scrollY > 100) {
                navbar.style.background = 'rgba(15, 23, 42, 0.98)';
                navbar.style.boxShadow = '0 2px 20px rgba(0, 0, 0, 0.1)';
            } else {
                navbar.style.background = 'rgba(15, 23, 42, 0.95)';
                navbar.style.boxShadow = 'none';
            }
        });
    }
    
    // 滚动时的元素动画
    function initScrollAnimations() {
        const observerOptions = {
            threshold: 0.1,
            rootMargin: '0px 0px -50px 0px'
        };
        
        const observer = new IntersectionObserver(function(entries) {
            entries.forEach(entry => {
                if (entry.isIntersecting) {
                    entry.target.style.opacity = '1';
                    entry.target.style.transform = 'translateY(0)';
                }
            });
        }, observerOptions);
        
        // 为需要动画的元素添加初始样式和观察者
        const animatedElements = document.querySelectorAll('.team-card, .rule-card, .tool-category, .goal-item');
        
        animatedElements.forEach((element, index) => {
            element.style.opacity = '0';
            element.style.transform = 'translateY(30px)';
            element.style.transition = `all 0.6s ease ${index * 0.1}s`;
            observer.observe(element);
        });
    }
    
    // 数字计数动画
    function initCounterAnimation() {
        const counters = document.querySelectorAll('.counter');
        
        const countUp = (element, target) => {
            let current = 0;
            const increment = target / 100;
            const timer = setInterval(() => {
                current += increment;
                element.textContent = Math.floor(current);
                
                if (current >= target) {
                    element.textContent = target;
                    clearInterval(timer);
                }
            }, 20);
        };
        
        const observer = new IntersectionObserver(function(entries) {
            entries.forEach(entry => {
                if (entry.isIntersecting) {
                    const target = parseInt(entry.target.getAttribute('data-target'));
                    countUp(entry.target, target);
                    observer.unobserve(entry.target);
                }
            });
        });
        
        counters.forEach(counter => observer.observe(counter));
    }
    
    // 打字机效果
    function initTypewriter() {
        const typewriterElement = document.querySelector('.typewriter');
        if (!typewriterElement) return;
        
        const text = typewriterElement.textContent;
        typewriterElement.textContent = '';
        
        let i = 0;
        const typeWriter = () => {
            if (i < text.length) {
                typewriterElement.textContent += text.charAt(i);
                i++;
                setTimeout(typeWriter, 100);
            }
        };
        
        setTimeout(typeWriter, 1000);
    }
    
    // 粒子背景效果
    function initParticleBackground() {
        const canvas = document.createElement('canvas');
        const ctx = canvas.getContext('2d');
        const hero = document.querySelector('.hero');
        
        if (!hero) return;
        
        canvas.style.position = 'absolute';
        canvas.style.top = '0';
        canvas.style.left = '0';
        canvas.style.width = '100%';
        canvas.style.height = '100%';
        canvas.style.pointerEvents = 'none';
        canvas.style.zIndex = '1';
        
        hero.appendChild(canvas);
        
        function resize() {
            canvas.width = hero.offsetWidth;
            canvas.height = hero.offsetHeight;
        }
        
        resize();
        window.addEventListener('resize', resize);
        
        const particles = [];
        const particleCount = 50;
        
        class Particle {
            constructor() {
                this.x = Math.random() * canvas.width;
                this.y = Math.random() * canvas.height;
                this.vx = (Math.random() - 0.5) * 0.5;
                this.vy = (Math.random() - 0.5) * 0.5;
                this.radius = Math.random() * 2 + 1;
                this.opacity = Math.random() * 0.5 + 0.2;
            }
            
            update() {
                this.x += this.vx;
                this.y += this.vy;
                
                if (this.x < 0 || this.x > canvas.width) this.vx *= -1;
                if (this.y < 0 || this.y > canvas.height) this.vy *= -1;
            }
            
            draw() {
                ctx.beginPath();
                ctx.arc(this.x, this.y, this.radius, 0, Math.PI * 2);
                ctx.fillStyle = `rgba(96, 165, 250, ${this.opacity})`;
                ctx.fill();
            }
        }
        
        for (let i = 0; i < particleCount; i++) {
            particles.push(new Particle());
        }
        
        function animate() {
            ctx.clearRect(0, 0, canvas.width, canvas.height);
            
            particles.forEach(particle => {
                particle.update();
                particle.draw();
            });
            
            // 绘制连接线
            particles.forEach((particle1, i) => {
                particles.slice(i + 1).forEach(particle2 => {
                    const dx = particle1.x - particle2.x;
                    const dy = particle1.y - particle2.y;
                    const distance = Math.sqrt(dx * dx + dy * dy);
                    
                    if (distance < 100) {
                        ctx.beginPath();
                        ctx.moveTo(particle1.x, particle1.y);
                        ctx.lineTo(particle2.x, particle2.y);
                        ctx.strokeStyle = `rgba(96, 165, 250, ${0.1 * (1 - distance / 100)})`;
                        ctx.lineWidth = 1;
                        ctx.stroke();
                    }
                });
            });
            
            requestAnimationFrame(animate);
        }
        
        animate();
    }
    
    // 技能标签动画
    function initSkillTags() {
        const skillTags = document.querySelectorAll('.skill-tag');
        
        skillTags.forEach((tag, index) => {
            tag.style.animationDelay = `${index * 0.1}s`;
            tag.classList.add('skill-animate');
        });
    }
    
    // 工具卡片悬停效果
    function initToolCardEffects() {
        const toolItems = document.querySelectorAll('.tool-item');
        
        toolItems.forEach(item => {
            item.addEventListener('mouseenter', function() {
                this.style.background = 'linear-gradient(45deg, #f8fafc, #e2e8f0)';
            });
            
            item.addEventListener('mouseleave', function() {
                this.style.background = 'white';
            });
        });
    }
    
    // 联系方式复制功能
    function initContactCopy() {
        const contactItems = document.querySelectorAll('.contact-item');
        
        contactItems.forEach(item => {
            item.style.cursor = 'pointer';
            item.addEventListener('click', function() {
                const text = this.querySelector('span').textContent;
                
                navigator.clipboard.writeText(text).then(() => {
                    // 显示复制成功提示
                    const originalText = this.querySelector('span').textContent;
                    this.querySelector('span').textContent = '已复制!';
                    
                    setTimeout(() => {
                        this.querySelector('span').textContent = originalText;
                    }, 2000);
                }).catch(() => {
                    console.log('复制失败');
                });
            });
        });
    }
    
    // 添加 CSS 动画类
    function addAnimationStyles() {
        const style = document.createElement('style');
        style.textContent = `
            .nav-menu.active {
                display: flex !important;
                position: absolute;
                top: 100%;
                left: 0;
                width: 100%;
                background: rgba(15, 23, 42, 0.98);
                flex-direction: column;
                padding: 1rem;
                box-shadow: 0 5px 15px rgba(0, 0, 0, 0.2);
            }
            
            .hamburger.active span:nth-child(1) {
                transform: rotate(-45deg) translate(-5px, 6px);
            }
            
            .hamburger.active span:nth-child(2) {
                opacity: 0;
            }
            
            .hamburger.active span:nth-child(3) {
                transform: rotate(45deg) translate(-5px, -6px);
            }
            
            .skill-animate {
                animation: skillFloat 2s ease-in-out infinite;
            }
            
            @keyframes skillFloat {
                0%, 100% { transform: translateY(0px); }
                50% { transform: translateY(-5px); }
            }
            
            .team-card:hover .team-avatar {
                transform: scale(1.1);
                transition: transform 0.3s ease;
            }
            
            .vision-circle:hover {
                transform: scale(1.1);
                border-color: #a855f7;
                transition: all 0.3s ease;
            }
        `;
        document.head.appendChild(style);
    }
    
    // 初始化所有功能
    function init() {
        addAnimationStyles();
        initSmoothScroll();
        initMobileNav();
        initNavbarScroll();
        initScrollAnimations();
        initCounterAnimation();
        initTypewriter();
        initParticleBackground();
        initSkillTags();
        initToolCardEffects();
        initContactCopy();
        
        // 页面加载完成后的淡入效果
        document.body.style.opacity = '0';
        document.body.style.transition = 'opacity 0.5s ease';
        
        setTimeout(() => {
            document.body.style.opacity = '1';
        }, 100);
        
        console.log('🚀 智创先锋队网站加载完成！');
    }
    
    // 启动初始化
    init();
});

// 页面性能优化
window.addEventListener('load', function() {
    // 预加载关键图片
    const criticalImages = [
        // 如果有图片的话可以在这里添加
    ];
    
    criticalImages.forEach(src => {
        const img = new Image();
        img.src = src;
    });
});

// 错误处理
window.addEventListener('error', function(e) {
    console.log('页面错误:', e.error);
});

// 工具函数
const utils = {
    // 节流函数
    throttle(func, limit) {
        let inThrottle;
        return function() {
            const args = arguments;
            const context = this;
            if (!inThrottle) {
                func.apply(context, args);
                inThrottle = true;
                setTimeout(() => inThrottle = false, limit);
            }
        };
    },
    
    // 防抖函数
    debounce(func, delay) {
        let timeoutId;
        return function() {
            const args = arguments;
            const context = this;
            clearTimeout(timeoutId);
            timeoutId = setTimeout(() => func.apply(context, args), delay);
        };
    },
    
    // 获取元素距离顶部的位置
    getOffset(element) {
        let offsetTop = 0;
        while (element) {
            offsetTop += element.offsetTop;
            element = element.offsetParent;
        }
        return offsetTop;
    }
}; 