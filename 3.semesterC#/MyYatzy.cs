using System;   
using System.Collections.Generic;

namespace KG1{
    class Program{
        static void Main(string[] args){
    int n = 0;
    List<int> upper = new List<int>();
    int total_upper = 0;
    List<int> lower = new List<int>();
    List<int> lw = lower;
    int total_lower = 0;
    int pos;
    int a= 0;
    int i; 
    int num;
    Random rnd = new Random();
    string input = Console.ReadLine();

    try{
        n=Int32.Parse(input);
        Console.WriteLine("AntalTerninger " + n);
    }
    catch{
        Console.WriteLine("Skal være et tal");
    }
    
    
    List<int> teringer = new List<int>();    

/*upper sections*/
/*her tager vi alle dem hvor vi bare skal finde en slags af hver tal på terningen
til det bruger vi blot to forloops til at tælle op til 6*/
    for (pos = 0; pos < 6; pos++)
    {
        rool_multiple_dies(n, teringer, rnd);

        for (i=0; i < n; i++)
        {
            
            if (teringer[i] == (pos + 1))
            {
                
                a = a + teringer[i]; 
                
            }
        }

        upper.Add(a);
        
        for (i=0; i < n; i++)
        {
           Console.Write(teringer[i] + " ");
        }
        Console.WriteLine("");
        Console.WriteLine(pos + 1 + "," + upper[pos]);
        Console.WriteLine("");
        a = 0;  
        teringer = new List<int>();   
    }

    for (pos = 0; pos < 6; pos++)
    {
        total_upper = total_upper + upper[pos];
    }

    Console.WriteLine(total_upper);
    /*her ser vi om der er opnået nok p int til at få bonusen*/
    if (total_upper >= 63)
    {
        Console.WriteLine("Bonus opnået");
        total_upper = total_upper + 50;
        Console.WriteLine("Første section score =" + total_upper);
    }
    else
    {
        Console.WriteLine("Bonus ikke opnået");
        Console.WriteLine("Første section score =" + total_upper);
    }
/*upper section end*/

/*lower section*/
/*her vi bruger en for loop til  at holde styr på hvor langt vi er nået i den her del af spilint
det bliver så sendt til funktion lower_section, hvor efter resultatet bliver p  intet af det skridt
vi er på og det til hørende terninger og til sidst regner vi den totale score ud*/
    for (num = 0; num < 9; num++)
    {   
        
        rool_multiple_dies(n, teringer, rnd);
        lower_section(n, num, teringer, lw);
        for ( i = 0; i < n; i++)
        {
            Console.Write(teringer[i] + " ");
        }
         
        
        total_lower = total_lower + lower[num];
        Console.WriteLine("");
        teringer = new List<int>();   
    }

    total_lower = total_lower + total_upper;

    Console.Write("Total score:" + total_lower);

    



}
/*her laver vi de forskellige dele til den anden del af spilint*/   
public static void lower_section (int n, int num, List<int> teringer, List<int> lw_arr)
{
    int[] pair1 = new int[2];
    int[] pair2=new int[2];
    int[] three=new int[3];
    int[] four=new int[4];
    int[] small_straight=new int[5];
    int[] large_straight=new int[5];
    int[] yatze=new int[5];       
    int total = 0;
    int pos;
    int length;
    int i;
    int j;


    switch (num)
    {   
        /*her bruger vi en funkrtion led_efter_ens som den bruger 
        til at finde det højste tal som der er flere af*/
        case 0:

            length = pair1.Length;
            
            led_efter_ens(length, n, pair1, teringer);
            for(i = 0; i < length; i++)
            {
                total = total + pair1[i];
            }
            lw_arr.Add(total);
            Console.WriteLine("Et par  = " + total);
        break;

        case 1:

            length = pair1.Length;
            led_efter_ens(length, n, pair1, teringer);
            
            for(i = 0; i < length; i++)
            {
                total = total + pair1[i];
            }

            if (pair1[0] != 0)
            {
                /*hvis vi finder noget for det første par køre vi en funktion som søger for
                vi ikke finder det samme til den næste del*/
                length = pair2.Length;
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
            

            lw_arr.Add(total);
            Console.WriteLine("To par  =" + total);
        break;

        case 2:

            length = three.Length;
            led_efter_ens(length, n, three, teringer);

            for(i = 0; i < length; i++)
            {
                total = total + three[i];
            }

            lw_arr.Add(total);
            Console.WriteLine("Tre ens  = "+ total);
        break;

        case 3:

            length = four.Length;
            led_efter_ens(length, n, four, teringer);

            for(i = 0; i < length; i++)
            {
                total = total + four[i];
            }

            lw_arr.Add(total);
            Console.WriteLine("Fire ens =" + total);
        break;

        case 4:
            pos = 0;
            length = small_straight.Length;
            for (i = 1; i <= 5; i++)
            {
                for(j = 0; j < n; j++)
                {
                    if (teringer[j] == i)
                    {
                        small_straight[pos] =teringer[j];
                        
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
            lw_arr.Add(total);
            Console.WriteLine("Small straight  = " + total);
        break;

        case 5:

            pos = 0;
            length = large_straight.Length;
            for (i = 2; i <= 6; i++)
            {
                for(j = 0; j < n; j++)
                {
                    if (teringer[j] == i)
                    {
                        large_straight[pos]=teringer[j];
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
            lw_arr.Add(total);
            Console.WriteLine("Large straight  = " + total);
        break;

        case 6:

            length = three.Length;
            led_efter_ens(length, n, three, teringer);
           
            for(i = 0; i < length; i++)
            {
                total = total + three[i];
            }

            if (three[0] != 0)
            {
                length = pair2.Length;
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
            

            lw_arr.Add(total);
            Console.WriteLine("Fuld Hus  = " + total);
        break;

        case 7:

        for(i = 0; i < n; i++)
        {
            total = total + teringer[i];
        }
        
        lw_arr.Add(total);
        Console.WriteLine("Chancen  = " + total);

        break;
        
        case 8:

            length = yatze.Length;
            led_efter_ens(length, n, yatze, teringer);

            for(i = 0; i < n; i++)
            {
            total = total + teringer[i];
            }

            lw_arr.Add(total);
            Console.WriteLine("Yatzy  =  " + total);
        break;
    }
   
   


}


/*her finder vi tal som vi allerede har brugt i vores forige array og fjerner
dem da de par ovs ikke må have de samme tal, her efter sender den så kopien af terning 
arrayet vider til led_efter_ens*/    
public static void ComAndRemove  (int n, int length, List<int> teringer, int[] com, int[] arr)
{
    
    int i;
    List <int> terning_copy=new List<int>();
    

    for (i = 0; i < n; i++)
    {
        terning_copy.Add(teringer[i]);
        if (terning_copy[i] == com[1])
        {
            terning_copy[i]=0;
        }
        
    }
    led_efter_ens(length, n, arr, terning_copy);
    
}

/*her bruger vi længende af vores array og tering arrayet til at finde to tre eller fem ens*/  
public static void led_efter_ens(int length, int n, int[] arr, List<int> teringer)
{
    int i; 
    int l = 0;
    int pos; 
    List<int> t=new List<int>();

    for (i = 0; i < n; i++)
    {
        t.Add(teringer[i]);
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
public static void rool_multiple_dies (int n, List<int> teringer, Random rnd)
{
    int pos;
    

    for (pos = 0; pos < n; pos++)
    {
        
        teringer.Add(rnd.Next(1, 6));
        

    }
    
}}}