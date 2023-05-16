import pandas as pd

def sms(classwork,database,homework,date):
  df = pd.read_csv(classwork)

  df["Status"] = df["Assignment State"]
  df.drop(["Assignment State","Surname","Mark","Comments","First Name"],axis = 1,inplace = True)
  df = df[df["Status"] == "Not done"]
  Db =  pd.read_csv(database)
  Database = Db.set_index('Email Address').T.to_dict('list')
  Key=df['Email Address'].tolist()
  X = list()
  j = 0
  for i in Key:
    X.append(Database[i])
    X[j][1] = "% s" %X[j][1]
    X[j][1] = "+" + X[j][1]
    j += 1
  
  my_df = pd.DataFrame(X)
  my_df["Name"] = my_df[0]
  my_df["Phone"] = my_df[1]
  my_df["Text"] = my_df[0] + " has not submitted " + homework + " which was given on " + date
  my_df.drop([0,1],axis = 1,inplace = True)

  my_df.to_excel("final_dataset.xlsx")

sms("Classwork.csv","Database.csv","Physics Electricity Homework","5th May")
