import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)
    var n = scanner.nextInt()

    while (n > 0) {
        val x = scanner.nextInt()
        val y = scanner.nextInt()f
        if (x <= y) {
            println("$x $y")
        } else {
            println("$y $x")
        }
        n--
    }
}