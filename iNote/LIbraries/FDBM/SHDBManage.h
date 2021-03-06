//
//  SHDBManage.h
//  iNote
//
//  Created by Sherwin.Chen on 12-12-7.
//
//

#import <Foundation/Foundation.h>
#import "FMDatabase.h"
#import "SHNoteUser.h"
#import "SHNotebook.h"
#import "SHNote.h"
/*
 class property: Singleton model
*/
typedef enum {
    NTF_NONE,  //无
    NTF_UPDATE,//is_delete
    NTF_DELETE,
    NTF_BOOKNAME,
    NTF_BOOKPATH
}NOTEBOOK_FIELD;

typedef enum {
    NF_NOTE_ID=0,
    NF_NOTEBOOK_NAME,
    NF_NOTE_PATH,
    NF_NOTE_DELETE,
    NF_NOTE_UPDATE,
    NF_NONE
}NOTE_FIELD;

@interface SHDBManage : NSObject
{
@private
    FMDatabase *db;
}

@property(readonly) NSString *dbErrorInfo;
//***************************************
//object init Method

/*
 初使化对象唯一方法
 */
+(SHDBManage*) sharedDBManage;

//********///
// NoteUser 
// get note user all info
-(SHNoteUser*) getNoteUserInfo;

// set note user info with SHNoteUser object [id user unique]
-(BOOL) setNoteUserDataToDB:(SHNoteUser*)_noteUser;

//delete Note User Data
-(BOOL) deleteNoteUserForDB;
////////////

//*********////
//Notebook info
//get notebook of all
//array for SHNoteBook class
-(NSMutableArray*) getAllNoteBooks;
//get notebook count with notebook name;
-(int) getNoteBookCountWithName:(NSString *)_stringName;

-(SHNotebook*) getNoteBookInfoWithNoteBookPath:(NSString*) _stringName;
-(SHNotebook*) getNoteBookInfoWithNoteBookName:(NSString*) _stringName;

//synchronization notebook table
-(void) synchronizationNoteBooK:(NSArray*) _arryData;

//notebook edit
-(BOOL) addNoteBook:(SHNotebook*) _noteBook;
-(BOOL) updateNoteBook:(SHNotebook*)_newNoteBook oldNoteBookName:(NSString*) _stringName;

/*删除操作说明
 逻辑删除: 不删除记录，只将记录中的delete字段设置为true,标识为已删除，用户界面不可见。 与服务器更新时，时行物理删除
 物理删除: 彻低的从数据库中将此记录删除。
 */
//逻辑删除
-(BOOL) deleteLogicNotebookWithNotebookName:(NSString*)_bookName;
//物理删除
-(BOOL) deletePhysicsNotebookWithNotebookName:(NSString*)_bookName;


//*************End/////


//*********////
//NoteRelation info
//SHNoteRelation//
-(NSMutableArray*) getNoteRelations;

//get all notes's path with someone notebook's path and it's more than 1
-(NSMutableArray*) getNoteRelationWithNotebookPath:(NSString*)_path;

//get noteRlation with note's path and it's only one
-(SHNoteRelation*) getNoteRelationWithNotePath:(NSString *)_path;

-(BOOL) addNoteRelation:(SHNoteRelation*)_noteRelation;

-(BOOL) deleteNoteRelationWithNotebookPath:(NSString*)_path;
-(BOOL) deleteNoteRelationWithNotePath:(NSString*)_path;
//*************End////


//*************////
//定时整理 note_id值[]
//Note info
-(NSMutableArray*)getAllNotes;
-(NSMutableArray*)getNotesWithNoteBookName:(NSString*)_book_name;
-(SHNote*)getNoteWithNoteID:(int)_note_id;
-(SHNote*)getNoteWithNotePath:(NSString*)_notepath;

-(BOOL) addNote:(SHNote*) _note;
-(BOOL) updateNote:(SHNote*) _note;

//逻辑删除［只提供id删除，因为本地增加，id才是唯一记录］
-(BOOL) deleteLogicNoteWithNoteID:(NSString *)_note_id;
//物理删除
-(BOOL) deletePhysicsNoteWithNoteID:(NSString *)_note_id;
//get note count with note_table_id
@end
