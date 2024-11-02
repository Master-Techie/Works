import mysql.connector

mydb = mysql.connector.connect(host='localhost', user='root', password='root', database='db001')
mycursor = mydb.cursor()
mycursor.execute("insert into t001 values(0002,'Divyam',18)")
mydb.commit()