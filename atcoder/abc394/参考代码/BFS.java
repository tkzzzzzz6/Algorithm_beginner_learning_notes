private Map<String, Boolean> status = new HashMap<String, Boolean>();
    private Queue<String> queue = new LinkedList<String>();
    public void BFSSearch(String startPoint) {
        //1.把起始点放入queue；
        queue.add(startPoint);
        status.put(startPoint, false);
        bfsLoop();
    }
    
    private void bfsLoop() {
        // BFS主循环,当队列不为空时继续遍历
        while(!queue.isEmpty()) {
            //  1) 从queue中取出队列头的点；更新状态为已经遍历。
            String currentQueueHeader = queue.poll(); //出队
            status.put(currentQueueHeader, true);
            // 打印当前访问的节点
            System.out.println(currentQueueHeader);
            //  2) 找出与此点邻接的且尚未遍历的点，进行标记，然后全部放入queue中。
            // 从图(graph)中获取当前节点(currentQueueHeader)的所有相邻节点
            // graph是一个存储图结构的变量,类似于邻接表
            // 比如对于一个图: A -> B,C 表示A连接着B和C
            // 那么graph.get("A")会返回一个包含"B"和"C"的列表
            List<String> neighborPoints = graph.get(currentQueueHeader);
            // 遍历所有邻接节点
            for (String poinit : neighborPoints) {
                // 检查邻接节点是否已被访问过
                if (!status.getOrDefault(poinit, false)) { // false表示节点未被访问
                    // 如果节点已在队列中则跳过,避免重复访问
                    if (queue.contains(poinit)) continue;
                    // 将未访问的邻接节点加入队列
                    queue.add(poinit);
                    // 将节点状态标记为待访问
                    status.put(poinit, false);
                }
            }
        }
    }