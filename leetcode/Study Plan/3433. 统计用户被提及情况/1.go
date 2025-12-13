func countMentions(numberOfUsers int, events [][]string) []int {
	ans := make([]int, numberOfUsers)
	// Event struct: timestamp, type (1=offline, -1=online, 2=HERE mention), user id
	type event struct {
		timestamp, type_, id int
	}
	es := []event{}
	all := 0
	// Process raw events and separate them into individual event objects
	for _, e := range events {
		curT, _ := strconv.Atoi(e[1])
		mention := e[2]
		if e[0] == "OFFLINE" {
			// Create offline(1) and online(-1) events 60 seconds later
			i, _ := strconv.Atoi(mention)
			es = append(es, event{curT, 1, i}, event{curT + 60, -1, i})
		} else if mention == "ALL" {
			all++
		} else if mention == "HERE" {
			// Increment all user mentions for HERE events (process later)
			all++
			es = append(es, event{curT, 2, -1})
		} else {
			// Direct user mentions: add immediately
			for _, s := range strings.Split(mention, " ") {
				i, _ := strconv.Atoi(s[2:])
				ans[i]++
			}
		}
	}

	// Sort events by timestamp, then by type (process in correct order)
	slices.SortFunc(es, func(a, b event) int {
		return cmp.Or(a.timestamp-b.timestamp, a.type_-b.type_)
	})

	// Calculate HERE mentions: count online users at each HERE event
	here := 0
	for _, e := range es {
		if e.type_ == 2 {
			// HERE mention: increment all currently online users by 'here' count
			here++
		} else {
			// OFFLINE/ONLINE event: update online status (1 removes, -1 adds)
			ans[e.id] += e.type_ * here
		}
	}

	// Add ALL mentions to all users
	for i := range ans {
		ans[i] += all
	}
	return ans
}
