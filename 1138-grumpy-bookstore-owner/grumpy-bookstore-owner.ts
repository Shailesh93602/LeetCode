function maxSatisfied(customers: number[], grumpy: number[], minutes: number): number {
     let sum : number = customers.reduce((prev, cur, i) => {
        if(i < minutes) return prev + cur;
        else return grumpy[i] ? prev + 0 : prev + cur;
    }, 0);

    let maxVal : number = sum;

    for(let i = 0; i + minutes < customers.length; i += 1){
        sum = grumpy[i] ? sum - customers[i] : sum;
        sum = grumpy[minutes + i] ? sum + customers[minutes + i] : sum;
        if(maxVal < sum) maxVal = sum;
    };

    return maxVal;
};