/*let msgBoard = {
    name:"Lokalt Autist Netværk",
    allMsg:["Hej", "KYS"],
    func:[]
};

msgBoard.putMsg = function(msg){
    this.allMsg.push(msg);
}

msgBoard.printMsg = function(){
    for (let i = 0; i < this.allMsg.length; i++) {
        console.log(this.allMsg[i]);       
    }
}

msgBoard.register = function(userFunc){
    this.func.push(userFunc);
}

msgBoard.sendAndNote = function(newMsg){
    this.putMsg(newMsg);
    for(let i = 0; i < this.func.length;i++){
        this.func[i](this.name, newMsg);
    }    
}*/

function bord2(name){
    this.name = name;
    this.allMsg = ["There seems to be nothing here"];
    this.func = [];

    this.putMsg = function(msg){
        this.allMsg.push(msg);
    }
    
    this.printMsg = function(){
        for (let i = 0; i < this.allMsg.length; i++) {
            console.log(this.allMsg[i]);       
        }
    }
    
    this.register = function(userFunc){
        this.func.push(userFunc);
    }
    
    this.sendAndNote = function(newMsg){
        this.putMsg(newMsg);
        for(let i = 0; i < this.func.length;i++){
            this.func[i](this.name, newMsg);
        }    
    }
}
let msgBoard = new bord2("Kool Kage Klubben");
msgBoard.putMsg("succy succy fuck fuck");
msgBoard.printMsg();
msgBoard.register(function(bordName, msg){
    console.log("New message in "+ bordName + " is says \"" + msg+"\"");
});
msgBoard.sendAndNote("Smelly dick cheese looking ass");

let succ = new bord2("Succ for Zuccbuck");
succ.putMsg("snot");
succ.printMsg();
succ.register(function(bordName, msg){
    console.log("New message in "+ bordName + " is says \"" + msg+"\"");
});
succ.sendAndNote("no succ");