 int lb = 0;
    int ub = s.length() - 1;

    while (lb < ub)
    {
        if (!isalpha(s[lb]))
            lb++;
        else if (!isalpha(s[ub]))
            ub--;
        else if (tolower(s[lb] != tolower(s[ub])))
            return false;
        else
        {
            lb++;
            ub--;
        }
    }

    return true;