package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var dirs = [][2]int{
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1},
}

func verify(chess [4][4]byte, s int) bool {
    for i := 0; i < 4; i++ {
        for j := 0; j < 4; j++ {
            c := chess[i][j]
            if c == '.' {
                continue
            }
            p := int(c - '0')
            mine := 0
            for k := 0; k < len(dirs); k++ {
                y0 := i + dirs[k][0]
                x0 := j + dirs[k][1]
                if y0 >= 0 && y0 < 4 && x0 >= 0 && x0 < 4 {
                    ts := y0*4 + x0
                    if (s & (1 << ts)) != 0 {
                        mine++
                    }
                }
            }
            if mine != p {
                return false
            }
        }
    }
    return true
}

func main() {
    reader := bufio.NewReader(os.Stdin)

    var chess [4][4]byte
    notMine := (1 << 16) - 1

    for i := 0; i < 4; i++ {
        line, _ := reader.ReadString('\n')
        line = strings.TrimSpace(line) // 例如 ".1.3"
        for j := 0; j < 4; j++ {
            chess[i][j] = line[j]
            if chess[i][j] != '.' {
                notMine -= 1 << (i*4 + j)
            }
        }
    }

    vis := make([][]int, 4)
    for i := 0; i < 4; i++ {
        vis[i] = make([]int, 4)
    }

    limit := 1 << 16
    for s := 0; s < limit; s++ {
        if (s|notMine) == notMine && verify(chess, s) {
            for r := 0; r < 4; r++ {
                for c := 0; c < 4; c++ {
                    if (s & (1 << (4*r + c))) == 0 {
                        vis[r][c] |= 1 // 一定不是雷
                    } else {
                        vis[r][c] |= 2 // 一定是雷
                    }
                }
            }
        }
    }

    for i := 0; i < 4; i++ {
        for j := 0; j < 4; j++ {
            if chess[i][j] == '.' {
                if vis[i][j] == 1 {
                    chess[i][j] = 'O'
                } else if vis[i][j] == 2 {
                    chess[i][j] = 'X'
                }
            }
        }
        fmt.Println(string(chess[i][:]))
    }
}
