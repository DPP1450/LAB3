## 物件
-  video紀錄video的基本資料（片名、基本收費、租借天數、超過天數收費、可累積點數）
- 三個繼承video物件的子物件，差別只在於基本收費、租借天數、超過天數收費、可累積點數的不同
    1. old
    2. new
    3. child
- customer 物件：紀錄顧客記本資訊（姓名、點數、累績消費金額）
- rentRecord 物件：一筆租借資料
- manage物件：儲存租借紀錄，顧客清單，video清單。用一個set把所有的record儲存起來，另外hashmap加快搜尋
    - videos：儲存所有video的set
    - customers：儲存所有顧客的set
    - rentRecords：儲存所有租借紀錄的vector
    - recordMap：key (顧客物件)，value(一個儲存該顧客租借紀錄的list)
    - addRentRecord：新增一比租借資料，計算所需費用，可以累積的點數
    - getPrice：計算一比租借的費用 
    - getRecord：把特定顧客的租借紀錄print 出來，包含點數及消費金額