import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
df = pd.read_csv('IndianEarthquakesListUpdate_Magnitudes.csv', low_memory=False)
# print(df.describe())
# print(df.columns)
# print(df.head())
# df = df.drop(df["Sl. No."].isnull(),axis=1)
df = df.dropna(subset=['Sl. No.'])
feature=["YEAR ", "MONTH ", "DATE", "ORIGIN TIME", "LAT (N)", "LONG (E)", "DEPTH (km)", "INTENSITY", "LOCATION", "REFERENCE"]
X = df[feature]
# for i in feature:
    # X[i]=X[i].astype('float64')
X["MONTH "] = [i for i in X["MONTH "] if '0'<i<'12']
print(X.head())
print(X.dtypes)
Y = df['MAGNITUDE'].astype('float64')
# print(Y.head())
# print(Y.dtypes)
X_train,X_test,Y_train,Y_test=train_test_split(X,Y,train_size=0.8, test_size=0.2)
md=KNeighborsClassifier(n_neighbors=2)
md.fit(X_train,Y_train)
print(md.predict(X_test))