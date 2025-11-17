import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {

    static int[][] dirs = new int[][] {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };

    static boolean verify(char[][] chess, int s) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                char c = chess[i][j];
                if (c == '.') continue;
                int p = c - '0';
                int mine = 0;
                for (int t = 0; t < dirs.length; t++) {
                    int y0 = i + dirs[t][0];
                    int x0 = j + dirs[t][1];
                    if (y0 >= 0 && y0 < 4 && x0 >= 0 && x0 < 4) {
                        int ts = y0 * 4 + x0;
                        if ((s & (1 << ts)) != 0) {
                            mine++;
                        }
                    }
                }
                if (mine != p) return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        char[][] chess = new char[4][];

        int notMine = (1 << 16) - 1;
        for (int i = 0; i < 4; i++) {
            chess[i] = sc.next().toCharArray();
            for (int j = 0; j < 4; j++) {
                if (chess[i][j] != '.') {
                    notMine -= 1 << (i * 4 + j);
                }
            }
        }

        // 收藏可能解, 1(0b01)一定是非雷，2(0b10)一定雷，3(0b11)则不确定
        int[][] vis = new int[4][4];

        // 枚举所有的可能性, 因为只有2^16种可能
        int range = 1 << 16;
        for (int i = 0; i < range; i++) {
            if ((i | notMine) == notMine && verify(chess, i)) {
                for (int r = 0; r < 4; r++) {
                    for (int c = 0; c < 4; c++) {
                        if ((i & (1 << (4 * r + c))) == 0) {
                            vis[r][c] |= 1;
                        } else {
                            vis[r][c] |= 2;
                        }
                    }
                }
            }
        }

        // 地雷图还原
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (chess[i][j] == '.') {
                    if (vis[i][j] == 1) chess[i][j] = 'O';
                    else if (vis[i][j] == 2) chess[i][j] = 'X';
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            System.out.println(new String(chess[i]));
        }
    }

}

