
#application for the grocery management

#import all the necessary modules
from tkinter import *
import tkinter.messagebox
import sqlite3

#class for Front End of the application

class Product:
    def __init__(self,root):
        #object refercence instance of database class
        p=Database()
        p.conn()

        self.root=root
        self.root.title("   GROCERY APPLICATION FOR HOUSE MANAGEMENT   ")
        self.root.geometry("1500x800")
        self.root.config(bg="lightblue")
        pId=StringVar()
        pName=StringVar()
        pPrice=StringVar()
        pQty=StringVar()
        pCompany=StringVar()
        pContact=StringVar()
   #performing functions start     
        def close():
            print("Product : close method called")
            close =tkinter.messagebox.askyesno("GROCERY APPLICATION FOR HOUSE MANAGEMENT","Really do u want to close system")
            if close>0 :
                root.destroy()
                print("Product :close method finished \n")
                return 
        
        def clear():
            print("Product :clear method called")
            self.txtpId.delete(0,END)
            self.txtpName.delete(0,END)
            self.txtpPrice.delete(0,END)
            self.txtpQty.delete(0,END)
            self.txtpCompany.delete(0,END)
            self.txtpContact.delete(0,END)
            print("Product :clear method finished")
        

        def insert():
            print("Product insert method called")
            if (len(pId.get())!=0):
                p.insert(pId.get(),pName.get(),pPrice.get(),pQty.get(),pCompany.get(),pContact.get())
                productList.delete(0,END)
                productList.insert(END,pId.get(),pName.get(),pQty.get(),pPrice.get(),pCompany.get(),pContact.get())
            else:
                tkinter.messagebox.askyesno("GROCERY APPLICATION FOR HOUSE MANAGEMENT","Enter the product id!!")
                print("Product :insert method finished\n")





            
            









        #creating a layout
        MainFrame = Frame(self.root,bg="pink")
        MainFrame.grid()
        HeadFrame = Frame(MainFrame,bd=1,padx=45,pady=10,bg='green',relief=RIDGE)
        HeadFrame.pack(side=TOP)
        self.ITitle = Label(HeadFrame,font=('arial',49,'bold'),fg='red',text='Grocery management System Sales Purchases',bg='green')
        self.ITitle.grid()
        OperationFrame =Frame(MainFrame, bd=2,width=1350,height=60,padx=50,pady=20,bg='deep pink',relief=RIDGE)
        OperationFrame.pack(side=BOTTOM)
        BodyFrame =Frame(MainFrame, bd=2,width=1300,height=460,padx=40,pady=20,bg='yellow',relief=RIDGE)
        BodyFrame.pack(side=BOTTOM)
        LeftBodyFrame =LabelFrame(BodyFrame, bd=2,width=600,height=420,padx=40,pady=10,bg='red',relief=RIDGE,font=('arial',15,'bold'),text='Product item details:')
        LeftBodyFrame.pack(side=LEFT)
        RightBodyFrame =LabelFrame(BodyFrame, bd=5,width=300,height=420,padx=49,pady=16,bg='gold',relief=RIDGE,font=('arial',15,'bold'),text='Product item information:')
        RightBodyFrame.pack(side=RIGHT)
        #Add the widgets to leftbodyframe

        #for the product id
        self.labelpId=Label(LeftBodyFrame,font=('arial',15,'bold'),text="Product Id",padx=2,pady=2,bg='red',fg='yellow')
        self.labelpId.grid(row=0,column=0,sticky=W)
        self.txtpId=Entry(LeftBodyFrame,font=('arial',17,'bold'),textvariable=pId,width=35)
        self.txtpId.grid(row=0,column=1,sticky=W)

        #for thr product name
        self.labelpName=Label(LeftBodyFrame,font=('arial',15,'bold'),text="Product Name",padx=2,pady=2,bg='red',fg='yellow')
        self.labelpName.grid(row=1,column=0,sticky=W)
        self.txtpName=Entry(LeftBodyFrame,font=('arial',17,'bold'),textvariable=pName,width=35)
        self.txtpName.grid(row=1,column=1,sticky=W) 

        #for the product price
        self.labelpPrice=Label(LeftBodyFrame,font=('arial',15,'bold'),text="Product Price",padx=2,pady=2,bg='red',fg='yellow')
        self.labelpPrice.grid(row=2,column=0,sticky=W)
        self.txtpPrice=Entry(LeftBodyFrame,font=('arial',17,'bold'),textvariable=pPrice,width=35)
        self.txtpPrice.grid(row=2,column=1,sticky=W)

        #for the product  quantity
        self.labelpQty=Label(LeftBodyFrame,font=('arial',15,'bold'),text="Product Quantity",padx=2,pady=2,bg='red',fg='yellow')
        self.labelpQty.grid(row=3,column=0,sticky=W)
        self.txtpQty=Entry(LeftBodyFrame,font=('arial',17,'bold'),textvariable=pQty,width=35)
        self.txtpQty.grid(row=3,column=1,sticky=W)

        #for the product company 
        self.labelpCompany=Label(LeftBodyFrame,font=('arial',15,'bold'),text="Manufacturing  Company",padx=2,pady=2,bg='red',fg='yellow')
        self.labelpCompany.grid(row=4,column=0,sticky=W)
        self.txtpCompany=Entry(LeftBodyFrame,font=('arial',17,'bold'),textvariable=pCompany,width=35)
        self.txtpCompany.grid(row=4,column=1,sticky=W)

        #for the product contact
        self.labelpContact=Label(LeftBodyFrame,font=('arial',15,'bold'),text="Company Contact",padx=2,pady=2,bg='red',fg='yellow')
        self.labelpContact.grid(row=5,column=0,sticky=W)
        self.txtpContact=Entry(LeftBodyFrame,font=('arial',17,'bold'),textvariable=pContact,width=35)
        self.txtpContact.grid(row=5,column=1,sticky=W)

        self.labelpC1=Label(LeftBodyFrame,padx=2,pady=2)
        self.labelpC1.grid(row=6,column=0,sticky=W)
        self.labelpC2=Label(LeftBodyFrame,padx=2,pady=2)
        self.labelpC2.grid(row=7,column=0,sticky=W)
        self.labelpC3=Label(LeftBodyFrame,padx=2,pady=2)
        self.labelpC3.grid(row=8,column=0,sticky=W)
        self.labelpC4=Label(LeftBodyFrame,padx=2,pady=2)
        self.labelpC4.grid(row=9,column=0,sticky=W)

        #scroll bar
        scroll=Scrollbar(RightBodyFrame)
        scroll.grid(row=0,column=1,sticky='ns')

        productList=Listbox(RightBodyFrame,width=40,height=16,font=('arial',12,'bold'),yscrollcommand=scroll.set)
        
        productList.grid(row=0,column=0,padx=8)
        scroll.config(command=productList)
        
        #buttons for the operation

        #save button
        self.buttonSaveData = Button(OperationFrame,text='Save',font=('arial',12,'bold'),height=1,width=10,bd=4,command=insert)
        self.buttonSaveData.grid(row = 0,column=0)

        #Show  button
        self.buttonShowData = Button(OperationFrame,text='Show',font=('arial',12,'bold'),height=1,width=10,bd=4)
        self.buttonShowData.grid(row = 0,column=1)
           
        #   clear  button   
        self.buttonClear = Button(OperationFrame,text='Clear',font=('arial',12,'bold'),height=1,width=10,bd=4,command=clear)
        self.buttonClear.grid(row = 0,column=2)

        #Delete button
        self.buttonDelete = Button(OperationFrame,text='Delete',font=('arial',12,'bold'),height=1,width=10,bd=4)
        self.buttonDelete.grid(row = 0,column=3)

        #Search button
        self.buttonSearch = Button(OperationFrame,text='Search',font=('arial',12,'bold'),height=1,width=10,bd=4)
        self.buttonSearch.grid(row = 0,column=4)

        #Update button
        self.buttonUpdate = Button(OperationFrame,text='Update',font=('arial',12,'bold'),height=1,width=10,bd=4)
        self.buttonUpdate.grid(row = 0,column=5)

        #Close button
        self.buttonClose = Button(OperationFrame,text='close',font=('arial',12,'bold'),height=1,width=10,bd=4,command=close)
        self.buttonClose.grid(row = 0,column=6)



#Backe end operation of ui
class Database:
    def conn(self):
        print("Database connecting ...:methos called")
        con =sqlite3.connect('inventory.db')
        cur=con.cursor()
        query="create table if not exists product(pid integer primary key, pname text,price text,qty text,company text,contact text)" #check here later
        cur.execute(query)
        con.commit()
        con.close()
        print("Database:connection methods finished\n")

    def insert(self,pid,name,price,qty,company,contact):
        print("Database:insert method called")
        con=sqlite3.connect("inventory.db")
        cur=con.cursor()
        query="insert into the product values(?,?,?,?,?,?)"
        cur.execute(query,(pid,name,price,qty,company,contact))
        con.commit()
        con.close()
        print("Database:insert methods finished\n")
    
    def show(self):
        print("Database:show method called")
        con=sqlite3.connect("inventory.db")
        cur=con.cursor()
        query="select * from  product"
        cur.execute(query)
        rows=cur.fetchall()
        con.closeprint("Database: show method finished")
        return rows
    
    def delete(self,pid):
        print("Database:show method called",pid)
        con=sqlite3.connect("inventory.db")
        cur=con.cursor()
        cur.execute("delete from product where pid=?",(pid,))
        con.commit()
        con.close()
        print(pid,"Database :delete method finidshed\n")
    
    def search(self,pid="",name="",price="",qty="",company="",contact=""):
        print("Database :Search method called",id)
        con=sqlite3.connect("inventory.db")
        cur=con.cursor()
        cur.execute("select * from product where pid=? or pname=? or \price=? or qty=? or company =? or contact=?")
        row=cur.fetchall()
        con.close()
        print(id,"Database:search method finished\n")
        return row
    
    def update(self,pid="",name="",price="",qty="",company="",contact=""):
        print("Database :Update method called",pid)
        con=sqlite3.connect("inventory.db")
        cur=con.cursor()
        cur.execute("update product set pid=? or pname=? or price=? or \qty=? or company =? or contact=? where id=?",(pid,name,price,qty,company,contact))
        con.commit()
        con.close()
        print(id,"Database :update method finished\n")
