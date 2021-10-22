using System;
using System.Collections;
using System.Collections.Generic;

namespace KG4
{
    class Program
    {
        public static void Main(string[] args)
        {
            Console.Clear();
            Menu selector = new Menu();
            MenuItem menu = new MenuItem("fancymenu") ;
            menu.add(new MenuItem("Punkt1"));
            menu.add(new MenuItem("Punkt2"));
            menu.add(new MenuItem("Punkt3"));
            MenuItem under = new MenuItem("Menu1");
            under.add(new MenuItem("nasdon"));
            under.add(new MenuItem("nasifd"));
            menu.add(under);
            infinateMenu infi = new infinateMenu("infinate");
            
            
            menu.add(infi);
            selector.Start(menu);
        }    
    }

    interface Imenu{
        string Title{get; set;}
        List<Imenu> menulist {get; set;}
    }
    class Menu : Imenu{
        public string Title{get; set;}
        public List<Imenu> menulist {get; set;}
        
        public void print(int j, int CurPos, Imenu ItemToDraw)
        { 
            Console.Clear();
            for (int i = 0; i < ItemToDraw.menulist.Count; i++)
            {
                if(j == i){
                    Console.ForegroundColor = ConsoleColor.Black;
                    Console.BackgroundColor = ConsoleColor.White;
                }
                Console.WriteLine(ItemToDraw.menulist[i].Title);                    
                
                Console.ResetColor();
            }
        }
        public void Start(Imenu startmenu)
        {
            int h = 0;
            
            print(h, h, startmenu);
            input(h, startmenu);
            
        }
        public void input(int pos, Imenu menu)
        {
            var k = Console.ReadKey();
            int CurPos = pos;
            Imenu PrevMenu = menu;
            infinateMenu InfiMatch = new infinateMenu("Match");
            while (k.KeyChar != 'q')
            {

                if (k.Key == ConsoleKey.UpArrow)
                {
                    pos--;
                    if(0 <= pos)
                    {
                        print(pos, CurPos, menu);   
                    }
                    else{
                        pos =0;
                    }
                    
                }
                if (k.Key == ConsoleKey.DownArrow)
                {
                    pos++;
                    
                        if(menu.menulist.Count > pos)
                        {
                            print(pos, CurPos, menu);
                        }
                        else{
                            pos =menu.menulist.Count -1;
                        }                   
                }
                if (k.Key == ConsoleKey.Enter){
                   
                    PrevMenu = menu;
                    menu = menu.menulist[pos];
                    if(menu.GetType() == InfiMatch.GetType()){
                            menu.menulist = new List<Imenu>();
                            for (int i = 1; i <= 6; i++){
                            menu.menulist.Add(new infinateMenu(i.ToString()));
                            }
                        }
                    CurPos = pos;
                    pos = 0;
                    print(pos, CurPos, menu);

                    
                }
                if (k.Key == ConsoleKey.Backspace){
                    menu = PrevMenu;
                    print(pos, CurPos, PrevMenu);
                }
                k = Console.ReadKey();
            }
        }
    }
    class infinateMenu : Imenu
    {
        public string Title{get; set;}
        public List<Imenu> menulist {get; set;} = new List<Imenu>();
        public infinateMenu (string title)
        {
            Title = title;
            
        }
        public void add(Imenu content)
        {
            menulist.Add(content);
        } 
    }
    class MenuItem : Imenu
    {
        public string Title{get; set;}
        
        public List<Imenu> menulist {get; set;} = new List<Imenu>();
        public MenuItem(string title)
        {
            Title = title;
        }
        public void add(Imenu content)
        {
            menulist.Add(content);
        }
    }

}
