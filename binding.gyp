{
    "targets":
    [
        {
            "target_name": "factorial",
            "sources": [
                "factorial.cpp",
                "factorialSync.cpp",
                "factorialAsync.cpp"
            ],
            "include_dirs" : ["<!(node -e \"require('nan')\")"]
        }
    ]
}
