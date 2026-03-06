/*
 * @Author: tkzzzzzz6
 * @Date: 2026-03-02 23:14:20
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-03-02 23:23:21
 */
// package class01;

public class code06_printB {
    public static void printB(int num) {
        for (int i = 31; i >= 0; i--) {
            System.out.print((num & (1 << i)) == 0 ? 0 : 1);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int num = 839288328;
        printB(num);
    }
}
