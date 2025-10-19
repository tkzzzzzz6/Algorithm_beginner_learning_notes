import kotlin.math.sqrt

fun isBeautifulSquare(s: String): Boolean {
    val length = s.length
    val n = sqrt(length.toDouble()).toInt()
    
    if (n * n != length) {
        return false
    }
    
    // Check top and bottom rows
    val topRow = s.substring(0, n)
    val bottomRow = s.substring(length - n)

    if (topRow != "1".repeat(n) || bottomRow != "1".repeat(n)) {
        return false
    }
    
    // Check left and right columns
    for (i in 0 until n) {
        if (s[i * n] != '1' || s[i * n + n - 1] != '1') {
            return false
        }
        
        // Check internal zeros, skip first and last rows
        if (i > 0 && i < n - 1) {
            if (s.substring(i * n + 1, i * n + n - 1).any { it != '0' }) {
                return false
            }
        }
    }
    
    return true
}

fun processTestCases(t: Int, testCases: List<String>): List<String> {
    return testCases.map { if (isBeautifulSquare(it)) "YES" else "NO" }
}

fun main() {
    val t = readLine()!!.toInt()
    val testCases = List(t) { readLine()!!.trim() }
    val results = processTestCases(t, testCases)
    results.forEach { println(it) }
}
