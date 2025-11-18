func isOneBitCharacter(bits []int) bool {
	n := len(bits)
	i := n-2
	for i >= 0 && bits[i] == 1{
		i--
	}
	return (n-i) % 2 == 0
} 