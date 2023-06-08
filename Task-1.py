import matplotlib.pyplot as plt
import pandas as pd
import numpy as np 
import seaborn as sns
data= pd.read_csv("output.csv")
sns.scatterplot(x=data.Distance,y=data.Overspeed,  
                hue=data.Cluster, 
                palette=sns.color_palette("hls", n_colors=4))
plt.xlabel("Annual income (k$)")
plt.ylabel("Spending Score (1-100)")
plt.title("Clustered: spending (y) vs income (x)")

plt.show()