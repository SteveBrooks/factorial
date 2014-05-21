{
    "targets":
    [
        {
            "target_name": "factorial",
            "sources": [
                "factorial.cpp",
                "factorialSync.cpp"
            ],
            "include_dirs" : ["<!(node -e \"require('nan')\")"]
        }
    ]
}
