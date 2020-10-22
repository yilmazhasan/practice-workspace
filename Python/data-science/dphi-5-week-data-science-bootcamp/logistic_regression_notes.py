TN = cm[0,0]
TP = cm[1,1]
FN = cm[1,0]
FP = cm[0,1]
sensitivity = TP / float(TP+FN)
specifivity = TN / float(TN+FP)


# The accuracy of the model = (TP + TN) / float(TP+TN+FP+FN)
# The Misclassification = 1- ((TP + TN) / float(TP+TN+FP+FN))
# Sensitivity or True Positive Rate = TP / float(TP+FN)
# Specificity or True Negative Rate = TN / float(TN+FP)
# Positive Predictive Value = TP / float(TP+FP)
# Negative Predictive Value = TN / float(TN+FN)
# Positive Likelihood Ratio = Sensitivity / (1-Specificity)
# Negative Likelihood Ratio = (1-Sensitivity) / Specificity

