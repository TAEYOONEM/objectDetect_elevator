import pymysql

class ResidentInfo :
    def __init__(self, user, passwd, host, db) :
        try :
            self.conn = pymysql.connect(
                user = user,
                passwd = passwd,
                host = host,
                db = db,
                charset = 'utf8'
            )

            self.cur = self.conn.cursor()

        except Exception as e :
            print(f'Can\'t connect  db : {e}')

    def execute(self,list_of_ids) :
        # lst = ['Warning']
        format_strings = ','.join(['%s'] * len(lst))
        self.cur.execute("SELECT floor FROM floors WHERE name in (%s)" % format_strings, tuple(list_of_ids))
        # self.cur.execute(query, tuple(list_of_ids))

    def fetchone(self) :
        try :
            return self.cur.fetchone()
        except Exception as e :
            print(f'{e}')
    
    def get_query(self) :        
        format_strings = ','.join(['%s'] * len(lst))
        query = f"SELECT floor FROM floors WHERE name in {format_strings}" 
        return query
    
    def commit(self) :
        self.conn.commit()

    def close(self) :
        self.conn.close()


if __name__ == "__main__" :
    lst = ['Warning']
    db = ResidentInfo(user = 'root', passwd='12345', host='localhost', db='resident')
    # q= db.get_query()
    db.execute(lst)
    print(db.fetchone())


















