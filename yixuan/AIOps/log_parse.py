import pandas as pd
import os
import re
import time
import pickle
from datetime import datetime

def save(filename, cls):
        with open(filename, 'wb') as f:
            pickle.dump(cls, f)

def load(filename):
    with open(filename, 'rb') as f:
        cls = pickle.load(f)
        return cls

def time_elapsed(time_front, time_back, format="%H:%M:%S"):
    try:
        time_front_array = datetime.strptime(time_front, format)
        time_back_array = datetime.strptime(time_back, format)
        time_elapsed = (time_back_array - time_front_array).seconds
        return str(time_elapsed)
    except:
        return "0"

def timestamp_to_str(timestamp=None, format='%Y-%m-%d %H:%M:%S'):
    if timestamp:
        time_tuple = time.localtime(timestamp)      # 把时间戳转换成时间元组
        result = time.strftime(format, time_tuple)  # 把时间元组转换成格式化的日期时间
        return result
    else:
        return time.strptime(format)

class lcsobj():
    # 初始化参数
    def __init__(self, objid, seq, lineid, refmt):
        # 0 ['this', 'is', 'a', 'pen'] 1 [\s]+
        self._refmt = refmt  # 这个是分隔符，空格 \n \r之类的
        if isinstance(seq, str) == True:
            self._lcsseq = re.split(self._refmt, seq.lstrip().rstrip())
        else:
            self._lcsseq = seq  # 日志键的list模式
        self._lineids = [lineid]
        self._pos = []  # _pos就是lcs列表中值为*的下标
        self._sep = "	"
        self._id = objid
        return

    # return seq和self._lcsseq相同元素的个数，用来计算最长公共子序列
    def getlcs(self, seq):
        if isinstance(seq, str) == True:
            seq = re.split(self._refmt, seq.lstrip().rstrip())
        count = 0
        lastmatch = -1
        for i in range(len(self._lcsseq)):
            # if self._lcsseq[i] == '*':
            if self._ispos(i) == True:
                continue
            for j in range(lastmatch + 1, len(seq)):
                if self._lcsseq[i] == seq[j]:
                    lastmatch = j
                    count += 1
                    break
        return count

    def insert(self, seq, lineid):
        if isinstance(seq, str) == True:
            seq = re.split(self._refmt, seq.lstrip().rstrip())
        self._lineids.append(lineid)
        temp = ""
        lastmatch = -1
        placeholder = False  # placeholder代表是否已经有*，如果没有*并且不匹配则添加一个*
        for i in range(len(self._lcsseq)):
            if self._ispos(i) == True:
                if not placeholder:
                    temp = temp + "* "
                placeholder = True
                continue
            for j in range(lastmatch + 1, len(seq)):
                if self._lcsseq[i] == seq[j]:
                    placeholder = False
                    temp = temp + self._lcsseq[i] + " "
                    lastmatch = j
                    break
                elif not placeholder:
                    temp = temp + "* "
                    placeholder = True
        temp = temp.lstrip().rstrip()
        self._lcsseq = re.split(" ", temp)

        self._pos = self._get_pos()
        self._sep = self._get_sep()

    def tojson(self, seq):

        temp = ""
        for i in self._lcsseq:
            temp = temp + i + " "
        ret = {}
        ret["lcsseq"] = temp
        ret["lineids"] = self._lineids
        ret["postion"] = self._pos
        ret["lcsseq_id"] = self._id
        ret["param"] = self.param(seq)
        return ret

    def length(self):
        return len(self._lcsseq)

    def param(self, seq):
        if isinstance(seq, str) == True:
            seq = re.split(self._refmt, seq.lstrip().rstrip())
        j = 0
        ret = []
        for i in range(len(self._lcsseq)):
            slot = []
            if self._ispos(i) == True:
                while j < len(seq):
                    if i != len(self._lcsseq) - 1 and self._lcsseq[i + 1] == seq[j]:
                        break
                    else:
                        slot.append(seq[j])
                    j += 1
                ret.append(slot)
            else:
                j += 1
        return ret

    def re_param(self, seq):
        if isinstance(seq, list) == True:
            seq = ' '.join(seq)
        seq = seq.lstrip().rstrip()
        ret = []
        print(self._sep)
        print(seq)
        p = re.split(self._sep, seq)
        for i in p:
            if len(i) != 0:
                ret.append(re.split(self._refmt, i.lstrip().rstrip()))
        if len(ret) == len(self._pos):
            return ret
        else:
            return []

    def _ispos(self, idx):
        for i in self._pos:
            if i == idx:
                return True
        return False

    def _tcat(self, seq, s, e):
        sub = ''
        for i in range(s, e + 1):
            sub += seq[i] + " "
        return sub.rstrip()

    def _get_sep(self):
        sep_token = []
        s = 0
        e = 0
        for i in range(len(self._lcsseq)):
            if self._ispos(i) == True:
                if s != e:
                    sep_token.append(self._tcat(self._lcsseq, s, e))
                s = i + 1
                e = i + 1
            else:
                e = i
            if e == len(self._lcsseq) - 1:
                sep_token.append(self._tcat(self._lcsseq, s, e))
                break

        ret = ""
        for i in range(len(sep_token)):
            if i == len(sep_token) - 1:
                ret += sep_token[i]
            else:
                ret += sep_token[i] + '|'
        return ret

    def _get_pos(self):
        pos = []
        for i in range(len(self._lcsseq)):
            if self._lcsseq[i] == '*':
                pos.append(i)
        return pos

    def get_id(self):
        return self._id


class lcsmap():
    def __init__(self, refmt):
        self._refmt = refmt
        self._lcsobjs = []
        self._lineid = 0
        self._id = 0
        return

    def insert(self, entry):
        seq = re.split(self._refmt, entry.lstrip().rstrip())
        obj = self.match(seq)
        # 这个是去看是否匹配
        # 如果不匹配，则添加新的obj到_lcsobjs列表中
        if obj == None:
            self._lineid += 1
            obj = lcsobj(self._id, seq, self._lineid, self._refmt)
            self._lcsobjs.append(obj)
            self._id += 1
        else:
            self._lineid += 1
            obj.insert(seq, self._lineid)

        return obj

    def match(self, seq):
        # seq = ['this', 'is', 'a', 'pen']
        if isinstance(seq, str) == True:
            seq = re.split(self._refmt, seq.lstrip().rstrip())
        bestmatch = None
        bestmatch_len = 0
        seqlen = len(seq)

        for obj in self._lcsobjs:
            objlen = obj.length()
            if objlen < seqlen / 2 or objlen > seqlen * 2: continue

            l = obj.getlcs(seq)

            if l >= seqlen / 2 and l > bestmatch_len:
                bestmatch = obj
                bestmatch_len = l
        return bestmatch

    def objat(self, idx):
        return self._lcsobjs[idx]

    def size(self):
        return len(self._lcsobjs)

    def dump(self):
        count = 0
        for i in self._lcsobjs:
            print(count, i.tojson())
            count += 1

def spell_log(df_log, df_type="train"):
    spell_result_path = "spell.pkl"
    if os.path.isfile(spell_result_path):
        slm = load(spell_result_path)
    else:
        slm = lcsmap('[\\s]+')
        for i in range(len(df_log)):
            log_message = df_log["value"][i]
            # print(log_message)
            sub = log_message.strip('\n')
            slm.insert(sub)
        # 将spell的训练结果保存在这里
        save('D:/bigdata/aiops/spell.pkl', slm)

    templates = [0] * df_log.shape[0]
    ids = [0] * df_log.shape[0]
    ParameterList = [0] * df_log.shape[0]
    time_interval = [0] * df_log.shape[0]
    for i in range(len(df_log)):
        log_message = df_log["value"][i].strip()
        obj = slm.insert(log_message)
        obj_json = obj.tojson(log_message)
        templates[i] = obj_json["lcsseq"]  # 获取该日志条目的日志键
        ids[i] = obj_json["lcsseq_id"]  # 获取日志键id 也就是事件编号
        ParameterList[i] = obj_json["param"]  # 取出log中的参数

    for id in range(len(df_log)):
        if id == 0:
            time_interval[id] = "0"
        else:
            time_last = df_log["timestamp"][id-1]
            time_now = df_log["timestamp"][id]
            elapsed = time_elapsed(time_last, time_now)
            time_interval[id] = elapsed
        ParameterList[id].append(time_interval[id])

    df_log['EventId'] = ids # 事件向量
    df_log['EventTemplate'] = templates  # 日志模板 日志键
    df_log["ParameterList"] = ParameterList
    return df_log

df_log = pd.read_csv('D:/bigdata/aiops/log_filebeat-testbed-log-envoy.csv')
df_log = spell_log(df_log, df_type='train')
df_log.to_csv('/home/bdp-jovyan/kyr/3_20_cloudbed3_log_filebeat-testbed-log-envoy.csv')