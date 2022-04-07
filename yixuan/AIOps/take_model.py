import os
import nltk
# nltk.download('punkt')
import numpy as np
import pandas as pd
from nltk.tokenize import word_tokenize
from gensim.models.doc2vec import Doc2Vec, TaggedDocument
from sklearn.ensemble import RandomForestClassifier
import lightgbm as lgb
import neptune.new as neptune
from tqdm.notebook import tqdm
from sklearn.model_selection import train_test_split
from sklearn.model_selection import StratifiedKFold, KFold

# 读取submit数据
submit = pd.read_csv('./data/preliminary_submit_dataset_a.csv')
submit.sort_values(by=['sn', 'fault_time'], inplace=True)
submit.reset_index(drop=True, inplace=True)

# 读取训练数据

# train_feature = np.loadtxt('./lib/train_feature_sm_alla.csv')
# train_label = np.loadtxt('./lib/train_label_sm_alla.csv')
# test_feature = np.loadtxt('./lib/test_feature_sm_alla.csv')

# train_feature = np.loadtxt('./lib/train_feature_sm_onel.csv')
# train_label = np.loadtxt('./lib/train_label_sm_onel.csv')
# test_feature = np.loadtxt('./lib/test_feature_sm_onel.csv')


# train_feature = np.loadtxt('./lib/train_feature_emb_alla.csv')
# train_label = np.loadtxt('./lib/train_label_emb_alla.csv')
# test_feature = np.loadtxt('./lib/test_feature_emb_alla.csv')

# train_feature = np.loadtxt('./lib/train_feature_emb_one.csv')
# train_label = np.loadtxt('./lib/train_label_emb_one.csv')
# test_feature = np.loadtxt('./lib/test_feature_emb_one.csv')

# train_feature = np.loadtxt('./lib/train_featureone7.csv')
# train_label = np.loadtxt('./lib/train_labelone7.csv')
# test_feature = np.loadtxt('./lib/test_featureone7.csv')

# train_feature = np.loadtxt('./lib/train_feature_sm_onel_h.csv')
# train_label = np.loadtxt('./lib/train_label_sm_onel_h.csv')

# mb_
train_feature = np.loadtxt('./lib/train_feature.csv')
train_label = np.loadtxt('./lib/train_label.csv')
# mb_
test_feature = np.loadtxt('./lib/test_featureone.csv')

from sklearn.metrics import f1_score


def f1__score(y_true, y_pred):
    return f1_score(y_true, y_pred, average="macro")


def feval_metrics1(y_pred, y_true):
    # y_pred = y_pred.reshape(4,-1).T
    y_pred = np.argmax(y_pred, axis=1)  # 4 分类
    return f1__score(y_true, y_pred)


# 参数
params = {'num_class': 4,
          'is_unbalance': True,
          'learning_rate': 0.001,

          #                 'num_leaves':28,
          #                  'max_depth':5,
          #                  'min_data_in_leaf':50,
          #                 'bagging_fraction':0.6,
          #                 'feature_fraction':0.9,
          'subsample': 0.8,
          'lambda_l1': 0.1,
          'lambda_l2': 0.2,
          'nthread': -1,
          'n_jobs': -1,
          'objective': 'multiclass',

          'seed': 2022}  #

f1scores = []


def lgm_model(lgb, train_x, train_y, x_submit):  #
    folds = 10
    seed = 2022
    kf = KFold(n_splits=folds, shuffle=True, random_state=seed)
    # 设置测试集，输出矩阵。每一组数据输出：[0,0,0,0]以概率值填入
    submit = np.zeros((x_submit.shape[0], 4))
    all_submit = []
    train_pred_res = np.zeros((train_feature.shape[0], 4))
    # 交叉验证分数
    for i, (train_index, valid_index) in enumerate(kf.split(train_x, train_y)):
        # print(i, len(train_index), len(valid_index))
        print('************************************ {} ************************************'.format(str(i + 1)))
        trn_x, trn_y, val_x, val_y = train_x[train_index], train_y[train_index], train_x[valid_index], train_y[
            valid_index]
        train_data = lgb.Dataset(trn_x, label=trn_y)
        valid_data = lgb.Dataset(val_x, label=val_y)
        lgbmodel = lgb.train({**params},
                             train_set=train_data,
                             valid_sets=[valid_data],
                             num_boost_round=15000,
                             early_stopping_rounds=200,
                             verbose_eval=100,
                             valid_names=['valid'])
        # train_pred = lgbmodel.predict(train_feature, num_iteration=lgbmodel.best_iteration)
        test_pred = lgbmodel.predict(val_x, num_iteration=lgbmodel.best_iteration)
        submit_pred = lgbmodel.predict(x_submit, num_iteration=lgbmodel.best_iteration)
        all_submit.append(submit_pred)
        # train_pred_res += train_pred
        submit += submit_pred
        run["vaid/f1"].log(feval_metrics1(test_pred, val_y))
        f1scores.append(feval_metrics1(test_pred, val_y))

    print(f1scores)
    print('平均', np.mean(f1scores))
    return submit, all_submit, np.mean(f1scores)


#################################### 初始化 ##########################################
run = neptune.init(
    project="zsaisai/lightgbm01",
    api_token="eyJhcGlfYWRkcmVzcyI6Imh0dHBzOi8vYXBwLm5lcHR1bmUuYWkiLCJhcGlfdXJsIjoiaHR0cHM6Ly9hcHAubmVwdHVuZS5haSIsImFwaV9rZXkiOiIyNmFjMDhkOC02OTUzLTRhZGQtYmEwOS1iOGJhNDgwNzU2ODQifQ==",
)  # your credentials
##################################Train Model ########################################

# test_submit,all_submit,
test_submit, all_submit, f1s = lgm_model(lgb, train_feature, train_label, test_feature)

##################################记 录 参 数 ########################################
run["parameters"] = params
run["sys/tags"].add(["调参"])
run["max/f1"].log(max(f1scores))
run["avg/avg_f1"].log(f1s)
run.stop()

## 所有模型平均

s = (test_submit) / 10

result = np.argmax(s, axis=1)

# 融合
submit['label'] = result
submit.to_csv('./test_1222.csv', index=0)
