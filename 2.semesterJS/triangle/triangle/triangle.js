console.log("Trangle");
let ting="#";
for(let i=0; i < 7;i++){
    console.log(ting);
    ting=ting + " " + "#"; 
}

console.log("Chessbord");

let t = 0;
let s1 = ' ' + '#' +' ' + '#' +' ' + '#' + ' ' +'#';
let s2 = "#" + " " + "#" + " " + "#" + " " + "#" + " ";
for(let i=0; i < 8;i++){
    if (t == 0){
        console.log(s1);
        t = 1
    }
    else if (t == 1){
        console.log(s2);
        t = 0
    }    
}

console.log("opg5");
let title = "Simpel IWP Demo";
let heading = "IWP demo";
let demoString = "JS Script er kørt";
renderPage(title,heading,demoString);
function renderPage(title,heading,demoString) { 
    console.log(`<!DOCTYPE html> \n\
        <html lang=\"da\"> \n\
          <head> \n\
            <meta charset=\"utf-8\"> \n\
            <title> ${title} </title> \n\
          </head> \n\
          <body> \n\
            <!-- page content --> \n\
            <h1> ` + heading + " </h1> \n\
            <script> \n\
              console.log(\""+ demoString + "\"); \n\
            </script> \n\
          </body> \n\
        </html>");
} 

console.log("opg6");
let strings=["Hejsa", "med", "dig!"];
console.log(avgOfString(strings));
function avgOfString(string){
    let total = 0;
    for(let i = 0;i < string.length; i++){
        total = total + string[i].length;
    } 

    return total /string.length;
}

