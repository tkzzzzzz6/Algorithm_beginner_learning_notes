class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        # Sort events by timestamp, then by event type (to process in chronological order)
        events.sort(key = lambda e:(int(e[1]),e[0][2]))

        # ans[i] stores the mention count for user i
        ans = [0]*numberOfUsers
        # online_t[i] stores when user i will be back online (0 means currently online)
        online_t = [0]*numberOfUsers

        for type_,timestamp,mention in events:
            curr_t = int(timestamp)
            # Handle OFFLINE event: user goes offline for 60 seconds
            if type_ == "OFFLINE":
                online_t[int(mention)] = curr_t + 60 
            # Handle ALL mentions: all users are mentioned
            elif mention == "ALL":
                for i in range(numberOfUsers):
                    ans[i] += 1 
            # Handle HERE mentions: only currently online users are mentioned
            elif mention == "HERE":
                for i,t in enumerate(online_t):
                    if curr_t >= t:
                        ans[i] += 1
            # Handle individual user mentions (e.g., "id0 id1 id2")
            else:
                for s in mention.split():
                    # Extract user ID from "id<number>" format
                    ans[int(s[2:])] += 1
        return ans
