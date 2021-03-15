import datetime  # datetime for getting dob input


def check_patient(user_test_):  # function to check whether positive or not and return a flag
    keys = dengue_normal_ranges.keys()
    print(keys)
    flag = []
    for each in user_test_:
        print(each)
        if each == "IgM_ratio":
            if user_test_[each] is not None:
                if dengue_normal_ranges[each] >= user_test_[each]:
                    flag.append(False)
                else:
                    flag.append(True)
            else:
                flag.append(False)

        if each == "HI":
            if user_test_[each] is not None:
                if dengue_normal_ranges[each] >= user_test_[each]:
                    flag.append(False)
                else:
                    flag.append(True)
            else:
                flag.append(False)

        if each == "Platelet count":
            if user_test_[each] is not None:
                if dengue_normal_ranges[each] <= user_test_[each]:
                    flag.append(False)
                else:
                    flag.append(True)
            else:
                flag.append(False)

    return flag


if __name__ == '__main__':

    dengue_normal_ranges = {"IgM_ratio": float(1.2), "HI": 1280, "Platelet count": 100000}              # the normal range dict
    #print(dengue_normal_ranges)

    patient_name = input("Enter Patient Name : ")                   # getting patient details
    gender = input("\nEnter your Gender : ")
    dob = input('\nEnter date of birth in DD-MM-YYYY format : ')
    try:
        day, month, year = map(int, dob.split('-'))
        date_ = datetime.date(year, month, day)                 #using Datetime to get date object
    except:
        print("Invalid Date")
    address = input("\nEnter your Address : ")
    weight = input("\nEnter Weight in KGs : ")
    print("\nEnter your Symptoms (type \"end\" after all symptoms) : ")
    x = []
    user_test = {}
    while True:
        value = input(" >> ")
        if value == "end":
            break
        x.append(value)
    sym = tuple(x)
    print("\nEnter your test values  : ")

    user_IgM_ratio = input("\nIgM Ratio : ")
    if user_IgM_ratio != "none":
        user_test["IgM_ratio"] = float(user_IgM_ratio)
    else:
        user_test["IgM_ratio"] = None

    user_HI = input("HI : ")
    if user_HI != "none":
        user_test["HI"] = int(user_HI)
    else:
        user_test["HI"] = None

    user_platelet_count = input("Platelet Count : ")
    if user_platelet_count != "none":
        user_test["Platelet count"] = int(user_platelet_count)
    else:
        user_test["Platelet count"] = None



    #print(user_test)
    #for each in user_test:
    #    print(each)

    flag_ = check_patient(user_test)            #call that function
    print(flag_)
    if False in flag_:      #chech returned value
        print(f'Patient : {patient_name} is Dengue - negative')
    else:
        print(f"Patient : {patient_name} is Dengue - positive")
