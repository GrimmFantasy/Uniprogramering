    
    
    let n = 0;
    let upper = [];
    let total_upper = 0;
    let lower = [];
    let lw = lower;
    let total_lower = 0;
    let pos;
    let a= 0;
    let i; 
    let num;
     
 
    n = process.argv[2]
    console.log("AntalTerninger " + n);
    
    
    let teringer = [];    

/*upper sections*/
/*her tager vi alle dem hvor vi bare skal finde en slags af hver tal på terningen
til det bruger vi blot to forloops til at tælle op til 6*/
    for (pos = 0; pos < 6; pos++)
    {
        rool_multiple_dies(n, teringer);

        for (i=0; i < n; i++)
        {
            if (teringer[i] == (pos + 1))
            {
                a = a + teringer[i]; 
            }
        }

        upper[pos] = a;

        console.log(pos + 1 + "," + upper[pos]);
        for (i=0; i < n; i++)
        {
           console.log(teringer[i]);
        }
    
        a = 0;  
    }

    for (pos = 0; pos < 6; pos++)
    {
        total_upper = total_upper + upper[pos];
    }

    console.log(total_upper);
    /*her ser vi om der er opnået nok p let til at få bonusen*/
    if (total_upper >= 63)
    {
        console.log("Bonus opnået");
        total_upper = total_upper + 50;
        console.log("Første section score =" + total_upper);
    }
    else
    {
        console.log("Bonus ikke opnået");
        console.log("Første section score =" + total_upper);
    }
/*upper section end*/

/*lower section*/
/*her vi bruger en for loop til  at holde styr på hvor langt vi er nået i den her del af spillet
det bliver så sendt til funktion lower_section, hvor efter resultatet bliver p  letet af det skridt
vi er på og det til hørende terninger og til sidst regner vi den totale score ud*/
    for (num = 0; num < 9; num++)
    {   
        
        rool_multiple_dies(n, teringer);
        lower_section(n, num, teringer, lw);

        for (i = 0; i < n; i++)
        {
            console.log(teringer[i]);
        }
        total_lower = total_lower + lower[num];
    }

    total_lower = total_lower + total_upper;

    console.log("Total score:" + total_lower);

    
    return 0;



/*her laver vi de forskellige dele til den anden del af spillet*/   
function lower_section (n, num, teringer, lw_arr)
{
    let pair1=[];
    let pair2=[];
    let three=[];
    let four=[];
    let small_straight=[];
    let large_straight=[];
    let yatze=[];       
    let total = 0;
    let pos;
    let length;
    let i;
    let j;


    switch (num)
    {   
        /*her bruger vi en funkrtion led_efter_ens som den bruger 
        til at finde det højste tal som der er flere af*/
        case 0:

            length = pair1.length;
            led_efter_ens(length, n, pair1, teringer);
            for(i = 0; i < length; i++)
            {
                total = total + pair1[i];
            }
            lw_arr[num] = total;
            console.log("Et par  = " + total);
        break;

        case 1:

            length = pair1.length;
            led_efter_ens(length, n, pair1, teringer);
            
            for(i = 0; i < length; i++)
            {
                total = total + pair1[i];
            }

            if (pair1[0] != 0)
            {
                /*hvis vi finder noget for det første par køre vi en funktion som søger for
                vi ikke finder det samme til den næste del*/
                length = pair2.length;
                ComAndRemove(n, length, teringer, pair1, pair2); 
            }

            if(pair1[0] == 0 || pair2[0] == 0)
            {
                total = 0;
            } 
            else
            {
                for(i = 0; i < length; i++)
                {
                    total = total + pair2[i];
                }
                
            }
            

            lw_arr[num] = total;
            console.log("To par  =" + total);
        break;

        case 2:

            length = three.length;
            led_efter_ens(length, n, three, teringer);

            for(i = 0; i < length; i++)
            {
                total = total + three;
            }

            lw_arr[num] = total;
            console.log("Tre ens  = "+ total);
        break;

        case 3:

            length = four.length;
            led_efter_ens(length, n, four, teringer);

            for(i = 0; i < length; i++)
            {
                total = total + four[i];
            }

            lw_arr[num] = total;
            console.log("Fire ens =" + total);
        break;

        case 4:
            pos = 0;
            length = small_straight.length;
            for (i = 1; i <= 5; i++)
            {
                for(j = 0; j < n; j++)
                {
                    if (teringer[j] == i)
                    {
                        small_straight[pos] = teringer[j];
                        
                        pos++;
                        j = n;
                    }
                }
            }
            if (pos != length)
            {
                for(i = 0; i < length; i++)
                {
                    total = 0;
                }
            }
            else
            {
                for(i = 0; i < length; i++)
                {
                    total = total + small_straight[i];
                }
            }
            lw_arr[num] = total;
            console.log("Small straight  = " + total);
        break;

        case 5:

            pos = 0;
            length = large_straight.length;
            for (i = 2; i <= 6; i++)
            {
                for(j = 0; j < n; j++)
                {
                    if (teringer[j] == i)
                    {
                        large_straight[pos] = teringer[j];
                        pos++;
                        j = n;
                    }
                }
            }
            if (pos != length)
            {
                for(i = 0; i < length; i++)
                {
                    total = 0;
                }
            }
            else
            {
                for(i = 0; i < length; i++)
                {
                    total = total + large_straight[i];
                }
            }
            lw_arr[num] = total;
            console.log("Large straight  = " + total);
        break;

        case 6:

            length = three.length;
            led_efter_ens(length, n, three, teringer);
           
            for(i = 0; i < length; i++)
            {
                total = total + three[i];
            }

            if (three[0] != 0)
            {
                length = pair2.length;
                ComAndRemove(n, length, teringer, three, pair2); 
            }
            
            if(three[0] == 0|| pair2[0] == 0)
            {
                total = 0;
            } 
            else
            {
                for(i = 0; i < length; i++)
                {
                    total = total + pair2[i];
                }
                
            }
            

            lw_arr[num] = total;
            console.log("Fuld Hus  = " + total);
        break;

        case 7:

        for(i = 0; i < n; i++)
        {
            total = total + teringer[i];
        }
        
        lw_arr[num] = total;
        console.log("Chancen  = " + total);

        break;
        
        case 8:

            length = yatze.length;
            led_efter_ens(length, n, yatze, teringer);

            for(i = 0; i < n; i++)
            {
            total = total + teringer[i];
            }

            lw_arr[num] = total;
            console.log("Yatzy  =  " + total);
        break;
    }
   
   


}


/*her finder vi tal som vi allerede har brugt i vores forige array og fjerner
dem da de par ovs ikke må have de samme tal, her efter sender den så kopien af terning 
arrayet vider til led_efter_ens*/    
function ComAndRemove  (n, length, teringer, com, arr)
{
    
    let i;
    let terning_copy=[];
    

    for (i = 0; i < n; i++)
    {
        terning_copy[i] = teringer[i];
        if (terning_copy[i] == com[1])
        {
            terning_copy[i] = 0;
        }
        
    }
    led_efter_ens(length, n, arr, terning_copy);
    
}

/*her bruger vi længende af vores array og tering arrayet til at finde to tre eller fem ens*/  
function led_efter_ens(length, n, arr,teringer)
{
    let i; 
    let l = 0;
    let pos; 
    let t=[];

    for (i = 0; i < n; i++)
    {
        t[i] = teringer[i];
    } 
    
    for (i = 6; i >= 1; i--)
    {
        for (pos = 0; pos < n; pos++)
        {

            if (t[pos] == i)
            {
               
                arr[l] = teringer[pos];
                t[pos] = 0;
                l++;
                if(l == length)
                {
                    pos = n;
                }
            }
            
        }

        if (l == length)
        {
            break;
        }
        else if (l != length)
        {
            l = 0;
        }
    }

    if (arr[0] != arr[length-1])
    {
        for(l=0;l<length;l++)
        {
            arr[l] = 0;
        }
    }    
    
}
    function rool_multiple_dies (n, teringer)
{
    let pos;

    for (pos = 0; pos < n; pos++)
    {
        teringer[pos] = Math.floor((Math.random() * 6) + 1);

    }
}