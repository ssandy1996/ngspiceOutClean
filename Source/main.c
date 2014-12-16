/************************************************************************
 * Copyright (C) 2014 S Sandeep Kumar (ee13b1025@iith.ac.in)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * ----------------------------------------------------------------------
 * Function:
 *		Allows to clean ngspice simulation output files to a neat .txt 
 * 		to import ot programs such as scilab and analyse.
 * ----------------------------------------------------------------------
 * Usage:
 * 		Will be updated soon.
 * ----------------------------------------------------------------------
 * Author:
 * 		S Sandeep Kumar
 * 		E-mail : ee13b1025@iith.ac.in
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc,char *argv[])
{  
   FILE *normal,*proper;
   int i=0;
   if(argv[1]!=NULL)
   {
	   char m[80];
	   normal=fopen(argv[1],"r");
       if(!normal)
       {
		   printf("\nError ! !  The file %s doesn't exist in the program directory\n\n",argv[1]);
           exit(1);
       }  
       proper=fopen("inter.txt","w");
       while(fscanf(normal,"%s",m)!=EOF)
       {   
	       if(isdigit(m[0])||((m[0]=='-')&&(isdigit(m[1]))))
	       {   
			   if(i<3)
		       {
				   i++;
			       fseek(proper,0,SEEK_SET);
			       continue;
		       }
		       fprintf(proper,"\t%s",m);
		       i++;
	       }
	       if(i%3==0)
	       {
			   fprintf(proper,"\n");
	       }
	   
	   }
	   fclose(proper);
	   proper=fopen("inter.txt","r");
	   FILE *final;
	   int k=0,a;
	   int t=strlen(argv[1]);
	   char n[80],*name;
	   name=(char *)malloc((t-4)*sizeof(char));
	   for(a=0;a<t-4;a++)
	   {
		   name[a]=*(argv[1]+a);
	   }
	   name=(char *)realloc(name,(t+5)*sizeof(char));	
	   strcat(name,"_test.txt");
	   final=fopen(name,"w");
       int check=0,pcheck=1,echeck=0;
	   while(fscanf(proper,"%s",n)!=EOF)
	   {
		   if(check==0)
		   {
			   for(i=0;n[i]!='\0';i++)
			   {
				   if(n[i]=='.')
				   {
					   echeck++;
					   break;
				   }
			   }
			   if(pcheck==echeck)
			   {
				   check = echeck+1;
				   fprintf(final,"\n");
			   }
			   pcheck=echeck;
		   }
	       else if(k%check==0)
	       {
			   fprintf(final,"\n");
		   }
		   for(i=0;i<80;i++)
		   {
			   if(!isspace(*n))
		       {
				   fprintf(final,"%s\t",n);
			       k++;
			       break;
		       }
	       }
	   }
       fclose(final);
       fclose(normal);
       fclose(proper);
       remove("inter.txt");
       printf("\nThe required data is stored in %s file\n\n",name);
       free(name);
   }
   else
   {
	   char m[80],*name,*name1;
       name=(char *)malloc(20*sizeof(char));
       printf("\nEnter the name of file to convert\n\nExample : data for data.txt file\n\n");
       gets(name);
       name1=(char *)malloc((strlen(name)+4)*sizeof(char));
       strcpy(name1,name);
       strcat(name1,".txt");
       normal=fopen(name1,"r");
       if(!normal)
       {
		   printf("\nError ! !  The file %s doesn't exist in the program directory\n\n",name1);
           exit(1);
       }
       free(name1);  
       proper=fopen("inter.txt","w");
       while(fscanf(normal,"%s",m)!=EOF)
       {   
	      if(isdigit(m[0])||((m[0]=='-')&&(isdigit(m[1]))))
	      {   
			  if(i<3)
		      {
				  i++;
			      fseek(proper,0,SEEK_SET);
			      continue;
		      }
		      fprintf(proper,"\t%s",m);
		      i++;
	      }
	      if(i%3==0)
	      {
			  fprintf(proper,"\n");
	      }			  
	   }
	   fclose(proper);
	   proper=fopen("inter.txt","r");
	   FILE *final;
	   char n[80];
	   name=(char *)realloc(name,(strlen(name)+9)*sizeof(char));
	   int k=0;	
	   strcat(name,"_test.txt");
	   final=fopen(name,"w");
	   int check=0,pcheck=1,echeck=0;
	   while(fscanf(proper,"%s",n)!=EOF)
	   {
		   if(check==0)
		   {
			   for(i=0;n[i]!='\0';i++)
			   {
				   if(n[i]=='.')
				   {
					   echeck++;
					   break;
				   }
			   }
			   if(pcheck==echeck)
			   {
				   check = echeck+1;
				   fprintf(final,"\n");
			   }
			   pcheck=echeck;
		   }
	       else if(k%check==0)
	       {
			   fprintf(final,"\n");
		   }
		   for(i=0;i<80;i++)
		   {
			   if(!isspace(*n))
		       {
				   fprintf(final,"%s\t",n);
			       k++;
			       break;
		       }
		   }
	   }
       fclose(final);
       fclose(normal);
       fclose(proper);
       remove("inter.txt");
       printf("\nThe required data is stored in %s file\n\n",name);
       free(name);
   }
   return 0;
}

/************************************************************************
 * End of main.c
 ***********************************************************************/
