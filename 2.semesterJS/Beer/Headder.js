let ale = document.querySelector('#ale');
let lager = document.querySelector('#lager');
let lambic = document.querySelector('#lambic');
let tst = document.createElement("h1");
let beerTypes={
    ales: ["Bitter", "Pale Ale", "Brown Ale", "Trappist", "Porter",  "Weizenbier"],
    lagers:["Pilsner", "Münchener", "Wiener", "Bock", "Porter"],
    wilds: ["Gueuze", "Faro", "Fruit"]
    };
    let i;


tst.innerHTML = "Vælg en Øl type";
document.body.insertBefore(tst, beerForm);
    
function print(name){
    console.log(name);
}

chk("btn");
document.getElementById("ale").addEventListener("mouseover", function(){
    console.log(ale.id);
})
/*document.body.addEventListener("mouseover", function(){
    let id = mousemover.
    conlose.log(id)
})*/
let selectList = document.createElement("select");
        selectList.id = "type";
        document.body.appendChild(selectList);
function chk(id){
document.getElementById(id).addEventListener("click", 
    function(){
        document.getElementById("type").innerHTML ="";  
        
        if (ale.checked == true){
            console.log("ale is checked");
  
            for(i = 0; i< beerTypes.ales.length; i++){
                console.log(beerTypes.ales[i]);
                let option = document.createElement("option");
                option.value = beerTypes.ales[i];
                option.text = beerTypes.ales[i];
                selectList.appendChild(option);
                
            }
        }
        else if (lager.checked == true){
            console.log("larger is checked");
            for(i = 0; i< beerTypes.lagers.length; i++){
                console.log(beerTypes.lagers[i]);
                let option = document.createElement("option");
                option.value = beerTypes.lagers[i];
                option.text = beerTypes.lagers[i];
                selectList.appendChild(option);
            }
        }
        else if (lambic.checked == true){
            console.log("lambic is checked");
            for(i = 0; i< beerTypes.wilds.length; i++){
                console.log(beerTypes.wilds[i]);
                let option = document.createElement("option");
                option.value = beerTypes.wilds[i];
                option.text = beerTypes.wilds[i];
                selectList.appendChild(option);
            }
        }
        
    });}

