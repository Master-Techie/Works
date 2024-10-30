import mysql.connector as msc

mydb = msc.connect(host="localhost",user="root",password="root",database="db001")

mycursor = mydb.cursor()

# mycursor.execute("create table students(roll_no int primary key,name varchar(20) not null,age int,contact_no bigint)")

# comm = "insert into students (roll_no,name,age,contact_no) values (%s,%s,%s,%s)"
# val = [(1,"Ajay",16,9794658720),(2,"Binod",17,8764978602),(3,"Chris",16,7798356401),(4,"Divya",15,9034684679),(5,"Esha",16,8437056712),(6,"Farhan",15,8806793342),(7,"Gurminder",17,6294037648),(8,"Harshvardhan",16,8884601798),(9,"Ishita",17,9933460578)]
# mycursor.executemany(comm,val)

# mycursor.execute("select * from students")
# mycursor.execute("select name,age from students")
# mycursor.execute("select * from students where age=16")mycursor.execute("select * from students order by name")
# mytable = mycursor.fetchall()
# print([i for i in mytable])

mydb.commit()