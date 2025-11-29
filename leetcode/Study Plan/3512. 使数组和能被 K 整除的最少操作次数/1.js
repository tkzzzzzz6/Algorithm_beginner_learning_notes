var minOperations = function(nums,k){
    let sum = 0;
    for(let num of nums){
        sum += num;
    }
    return sum %k;
};
