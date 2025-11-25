package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// ========== 输入输出模板部分 ==========

// sc: Scanner 用于高效读取输入
// 使用 bufio.Scanner 比 fmt.Scan 快很多，适合大量输入
var sc = bufio.NewScanner(os.Stdin)

// out: Writer 用于高效输出
// 使用 bufio.Writer 比 fmt.Print 快很多，适合大量输出
var out = bufio.NewWriter(os.Stdout)

// next(): 读取下一个单词（字符串）
// 工作原理：
//  1. sc.Scan() - 扫描输入流，读取下一个token（默认是行，Split后是单词）
//  2. sc.Text() - 获取扫描到的文本内容
func next() string {
	sc.Scan()
	return sc.Text()
}

// nextInt(): 读取下一个整数
// 工作原理：
//  1. 调用 next() 获取字符串
//  2. strconv.Atoi() 将字符串转换为整数
//  3. 忽略错误（_），如果输入不是数字会返回0
func nextInt() int {
	v, _ := strconv.Atoi(next())
	return v
}

// nextFloat64(): 读取下一个浮点数
// 工作原理：
//  1. 调用 next() 获取字符串
//  2. strconv.ParseFloat() 将字符串转换为 float64（64位精度）
func nextFloat64() float64 {
	v, _ := strconv.ParseFloat(next(), 64)
	return v
}

func main() {
	// defer out.Flush(): 延迟执行，程序结束前刷新输出缓冲区
	// 重要：如果没有这行，所有输出可能不会显示！
	defer out.Flush()

	// sc.Split(bufio.ScanWords): 设置扫描器按单词分割输入
	// 默认是按行分割（bufio.ScanLines），改为按单词后可以逐个读取
	sc.Split(bufio.ScanWords)

	t := 1
	// t = nextInt()  // 如果需要读取测试用例数，取消注释
	for ; t > 0; t-- {
		solve()
	}
}

// ========== 解题函数 ==========
func solve() {
	// 读取浮点数
	r := nextFloat64()

	// 使用 fmt.Fprintf 输出到缓冲区
	// 注意：必须用 fmt.Fprintf(out, ...) 而不是 fmt.Printf(...)
	// Fprintf 的第一个参数是 io.Writer，这里传入 out 缓冲区
	// %.2f 表示保留2位小数，\n 表示换行
	fmt.Fprintf(out, "%.2f\n", r+1)
}
