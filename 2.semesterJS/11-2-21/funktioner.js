let diceRoll=[1,6,6,2,3,4,6];


get6s_v1(diceRoll);
get6s_v2(diceRoll);
get6s_v3(diceRoll, is6);


function get6s_v1(dices){
    for(let i = 0; i < dices.length; i++){
        if (dices[i] == 6){
            console.log(i+":"+dices[i]);
        }
    }
}

function is6(v){
    if (v == 6){
        return true;
    }
    else{
        return false;
    }
}

let compare =function is1(v){
    if (v == 1){
        return true;
    }
    else{
        return false;
    }
}

function get6s_v2(dices){
    for(let i = 0; i < dices.length; i++){       
       if(is6(dices[i])){
           console.log(i+":"+dices[i])
       }       
    }
}

function get6s_v3(dices, comp){
    for(let i = 0; i < dices.length; i++){       
        if(comp(dices[i])){
            console.log(i+":"+dices[i])
        }       
     }
}

findDices_v1(diceRoll, compare)
function findDices_v1(dices, comp){
    for(let i = 0; i < dices.length; i++){       
        if(comp(dices[i])){
            console.log(i+":"+dices[i])
        }       
     }
}

function lessThan(i){
    return function(j){
        return j <= i;
    }
}

let lessThan3 = lessThan(3);

findDices_v2(diceRoll)
function findDices_v2(dices){
    for(let i = 0; i < dices.length; i++){    
        if (lessThan3(dices[i]))
            console.log(i+":"+dices[i]);       
    }
}